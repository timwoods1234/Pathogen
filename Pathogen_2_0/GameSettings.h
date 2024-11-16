#ifndef __GAMESETTINGS_H__
#define __GAMESETTINGS_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class GameSettings : public TSingleton<GameSettings>,
					 public TXMLObject
{
public:
	GameSettings();

	~GameSettings();

	int GetMaxEggs() const;

	int GetMaxEnemies() const;

	int GetGridSize() const;

	int GetTileSize() const;

	int GetMaxShield() const;

	float GetEnemyEscapeDistance() const;

	float GetEnemyDestroyDistance() const;

	TXMLObject* HandleLoadElement(const TString& strId, TDynamicSet<TDataVariant>& objects);

	void HandleLoadAttributes(TDynamicSet<TDataVariant>& objects);

	void FinaliseLoad();

	void Write(TXMLWriter& writer);

private:
	int m_maxEggs;
	int m_maxEnemies;
	int m_maxShield;

	int m_gridSize;
	int m_tileSize;

	float m_enemyEscapeDistance;
	float m_enemyDestroyDistance;
};

#endif
