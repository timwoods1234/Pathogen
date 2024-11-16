#ifndef __PLAYERSTATS_H__
#define __PLAYERSTATS_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class PlayerStats : public TSingleton<PlayerStats>
{
public:
	PlayerStats();

	int GetCurrentScore() const;

	void SetCurrentScore(int score);

	// TODO: add continues
	int GetCurrentLives() const;

	void SetCurrentLives(int lives);

	unsigned int GetCurrentLevel() const;

	void SetCurrentLevel(unsigned int level);

	int GetCurrentShield() const;

	void SetCurrentShield(int shield);

	bool GetGameInProgress() const;

	void SetGameInProgress(bool gameInProgress);

	void SetPlayTime(float playTime);

	float GetPlayTime() const;

private:
	int m_currentScore;

	int m_currentLives;

	int m_currentShield;

	bool m_gameInProgress;

	unsigned int m_currentLevel;

	float m_playTime;
};

#endif
