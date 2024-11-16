#include "HallOfFame.h"

#define MAX_HOF_ENTRIES 10

DefineSingleton(HallOfFame);

//-------------------------------------------------------------------------------
HallOfFame::HallOfFame()
{
	TXMLReader reader("Assets/Save/HallOfFame.xml", *this);

	if (reader.WasError())
	{
		Save();
	}

	m_currentName = TString::GetEmptyString();
}

//-------------------------------------------------------------------------------
unsigned int HallOfFame::GetNumEntries() const
{
	return m_hallOfFameEntries.GetSize();
}

//-------------------------------------------------------------------------------
const HallOfFameEntry* HallOfFame::GetEntry(unsigned int index) const
{
	if (index < m_hallOfFameEntries.GetSize())
	{
		return &(m_hallOfFameEntries[index]);
	}

	return NULL;
}

//-------------------------------------------------------------------------------
bool HallOfFame::IsScoreWorthy(int score) const
{
	bool result = false;

	int numEntries = GetNumEntries();

	if (numEntries < MAX_HOF_ENTRIES)
	{
		result = true;
	}
	else
	{
		int lowestScore = m_hallOfFameEntries[numEntries - 1].GetTotalScore();
		result = score > lowestScore;
	}

	return result;
}

//-------------------------------------------------------------------------------
void HallOfFame::AddEntry(const TString& playerName, int totalScore)
{
	HallOfFameEntry entry(playerName, totalScore);

	m_hallOfFameEntries.Add(entry);
}

//-------------------------------------------------------------------------------
void HallOfFame::SortEntries()
{
	for (unsigned int i = 0; i < m_hallOfFameEntries.GetSize(); i++)
	{
		for (unsigned int j = i + 1; j < m_hallOfFameEntries.GetSize(); j++)
		{
			if (m_hallOfFameEntries[j].GetTotalScore() > m_hallOfFameEntries[i].GetTotalScore())
			{
				HallOfFameEntry temp = m_hallOfFameEntries[i];

				m_hallOfFameEntries[i] = m_hallOfFameEntries[j];

				m_hallOfFameEntries[j] = temp;
			}
		}
	}

	while (m_hallOfFameEntries.GetSize() > MAX_HOF_ENTRIES)
	{
		m_hallOfFameEntries.RemoveAt(m_hallOfFameEntries.GetSize() - 1);
	}
}

//-------------------------------------------------------------------------------
TXMLObject* HallOfFame::HandleLoadElement(const TString& strID, TDynamicSet<TDataVariant>& objects)
{
	if (strID == "HallOfFameEntry")
	{
		TString playerName = TDataVariant::Find("name", objects).GetString();
		int score = TDataVariant::Find("score", objects).GetInt();

		AddEntry(playerName, score);
	}

	return NULL;
}

//-------------------------------------------------------------------------------
void HallOfFame::HandleLoadAttributes(TDynamicSet<TDataVariant>& objects)
{
}

//-------------------------------------------------------------------------------
void HallOfFame::FinaliseLoad()
{
	SortEntries();
}

//-------------------------------------------------------------------------------
void HallOfFame::Write(TXMLWriter& writer)
{
	for (unsigned int index = 0; index < m_hallOfFameEntries.GetSize(); index++)
	{
		writer.WriteDummyElementStart("HallOfFameEntry");

		writer.WriteAttribute("name", m_hallOfFameEntries[index].GetPlayerName().GetPointer());
		writer.WriteAttribute("score", m_hallOfFameEntries[index].GetTotalScore());

		writer.WriteDummyElementEnd("HallOfFameEntry");
	}
}

//-------------------------------------------------------------------------------
void HallOfFame::Save()
{
	// TODO: writer should EnsureFileExists
	TXMLWriter writer("Assets/Save/HallOfFame.xml", "HallOfFame", *this);
}

//-------------------------------------------------------------------------------
const TString& HallOfFame::GetCurrentName() const
{
	return m_currentName;
}

//-------------------------------------------------------------------------------
void HallOfFame::SetCurrentName(const TString& name)
{
	m_currentName = name;
}
