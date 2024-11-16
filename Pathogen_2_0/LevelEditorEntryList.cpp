#include "LevelEditorEntryList.h"

//-------------------------------------------------------------------------------
LevelEditorEntryList::LevelEditorEntryList()
{
}

//-------------------------------------------------------------------------------
LevelEditorEntryList::~LevelEditorEntryList()
{
	ClearAllEntries();
}

//-------------------------------------------------------------------------------
void LevelEditorEntryList::ClearAllEntries()
{
	for (unsigned int index = 0; index < m_entries.GetSize(); index++)
	{
		TSafeDelete(m_entries[index]);
	}

	m_entries.Clear();
}

//-------------------------------------------------------------------------------
unsigned int LevelEditorEntryList::GetNumEntries() const
{
	return m_entries.GetSize();
}

//-------------------------------------------------------------------------------
const LevelEditorEntry* LevelEditorEntryList::GetEntry(unsigned int index) const
{
	const LevelEditorEntry* result = NULL;

	if (index < m_entries.GetSize())
	{
		result = m_entries[index];
	}

	return result;
}

//-------------------------------------------------------------------------------
const LevelEditorEntry* LevelEditorEntryList::GetEntry(const TVector2& position) const
{
	const LevelEditorEntry* result = NULL;

	for (unsigned int index = 0; index < m_entries.GetSize(); index++)
	{
		if (m_entries[index]->GetPosition() == position)
		{
			result = m_entries[index];
		}
	}

	return result;
}

//-------------------------------------------------------------------------------
void LevelEditorEntryList::AddEntry(LevelEditorEntry& entry)
{
	LevelEditorEntry* newEntry = TNew LevelEditorEntry(entry.GetDefinition(), entry.GetPosition());

	m_entries.Add(newEntry);
}

//-------------------------------------------------------------------------------
void LevelEditorEntryList::RemoveEntry(const LevelEditorEntry& entry)
{
	LevelEditorEntry* existingEntry = NULL;

	for (unsigned int index = 0; index < m_entries.GetSize(); index++)
	{
		if (m_entries[index]->GetDefinition() == entry.GetDefinition() &&
			m_entries[index]->GetPosition() == entry.GetPosition())
		{
			existingEntry = m_entries[index];
			break;
		}
	}

	if (existingEntry != NULL)
	{
		m_entries.Remove(existingEntry);

		TSafeDelete(existingEntry);
	}
}

//-------------------------------------------------------------------------------
TXMLObject* LevelEditorEntryList::HandleLoadElement(const TString& strId, TDynamicSet<TDataVariant>& objects)
{
	if (strId == "LevelEntry")
	{
		TString definitionName = TDataVariant::Find("Definition", objects).GetString();

		TEntityDefinition* definition = TEntityDefinition::Acquire(definitionName.GetPointer());

		if (definition != NULL)
		{
			float x = TDataVariant::Find("x", objects).GetFloat();
			float y = TDataVariant::Find("y", objects).GetFloat();

			TVector2 position(x, y);

			LevelEditorEntry newEntry(definition, position);

			AddEntry(newEntry);

			TEntityDefinition::Release(definition);
		}
		else
		{
			TDebugPrint(("[LevelEditorEntryList::HandleLoadElement] Unable to find entity definition: %s", definitionName.GetPointer()));
		}
	}

	return NULL;
}

//-------------------------------------------------------------------------------
void LevelEditorEntryList::HandleLoadAttributes(TDynamicSet<TDataVariant>& objects)
{
}

//-------------------------------------------------------------------------------
void LevelEditorEntryList::FinaliseLoad()
{
}

//-------------------------------------------------------------------------------
void LevelEditorEntryList::Write(TXMLWriter& writer)
{
	unsigned int numEntries = GetNumEntries();
	const LevelEditorEntry* entry = NULL;

	for (unsigned int index = 0; index < numEntries; index++)
	{
		entry = GetEntry(index);

		if (entry != NULL)
		{
			writer.WriteDummyElementStart("LevelEntry");

			writer.WriteAttribute("Definition", entry->GetDefinition()->GetId().GetPointer());

			writer.WriteAttribute("x", entry->GetPosition().x);
			writer.WriteAttribute("y", entry->GetPosition().y);

			writer.WriteDummyElementEnd("LevelEntry");
		}
	}
}
