#include "HallOfFameEntry.h"

//-------------------------------------------------------------------------------
HallOfFameEntry::HallOfFameEntry()
:	m_totalScore(0)
{
	m_playerName = TString::GetEmptyString();
}

//-------------------------------------------------------------------------------
HallOfFameEntry::HallOfFameEntry(const TString& playerName, int score)
:	m_totalScore(score),
	m_playerName(playerName)
{
}

//-------------------------------------------------------------------------------
const TString& HallOfFameEntry::GetPlayerName() const
{
	return m_playerName;
}

//-------------------------------------------------------------------------------
int HallOfFameEntry::GetTotalScore() const
{
	return m_totalScore;
}

//-------------------------------------------------------------------------------
HallOfFameEntry& HallOfFameEntry::operator= (const HallOfFameEntry& other)
{
	m_totalScore = other.m_totalScore;
	m_playerName = other.m_playerName;

	return *this;
}