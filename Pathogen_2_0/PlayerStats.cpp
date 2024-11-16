#include "PlayerStats.h"

//-------------------------------------------------------------------------------
DefineSingleton(PlayerStats);

//-------------------------------------------------------------------------------
PlayerStats::PlayerStats()
:	m_currentScore(0),
	m_currentLives(0),
	m_currentLevel(1),
	m_gameInProgress(false),
	m_playTime(0.f)
{
}

//-------------------------------------------------------------------------------
int PlayerStats::GetCurrentScore() const
{
	return m_currentScore;
}

//-------------------------------------------------------------------------------
void PlayerStats::SetCurrentScore(int score)
{
	m_currentScore = score;
}

//-------------------------------------------------------------------------------
int PlayerStats::GetCurrentLives() const
{
	return m_currentLives;
}

//-------------------------------------------------------------------------------
void PlayerStats::SetCurrentLives(int lives)
{
	m_currentLives = lives;
}

//-------------------------------------------------------------------------------
unsigned int PlayerStats::GetCurrentLevel() const
{
	return m_currentLevel;
}

//-------------------------------------------------------------------------------
void PlayerStats::SetCurrentLevel(unsigned int level)
{
	m_currentLevel = level;
}

//-------------------------------------------------------------------------------
int PlayerStats::GetCurrentShield() const
{
	return m_currentShield;
}

//-------------------------------------------------------------------------------
void PlayerStats::SetCurrentShield(int shield)
{
	m_currentShield = shield;
}

//-------------------------------------------------------------------------------
bool PlayerStats::GetGameInProgress() const
{
	return m_gameInProgress;
}

//-------------------------------------------------------------------------------
void PlayerStats::SetGameInProgress(bool gameInProgress)
{
	m_gameInProgress = gameInProgress;
}

//-------------------------------------------------------------------------------
void PlayerStats::SetPlayTime(float playTime)
{
	m_playTime = playTime;
}

//-------------------------------------------------------------------------------
float PlayerStats::GetPlayTime() const
{
	return m_playTime;
}