#ifndef __HALLOFFAMEENTRY_H__
#define __HALLOFFAMEENTRY_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class HallOfFameEntry
{
public:
	HallOfFameEntry();

	HallOfFameEntry(const TString& playerName, int score);

	const TString& GetPlayerName() const;

	int GetTotalScore() const;

	HallOfFameEntry& operator= (const HallOfFameEntry& other);

private:
	TString m_playerName;

	int m_totalScore;
};

#endif
