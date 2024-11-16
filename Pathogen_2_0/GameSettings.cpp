#include "GameSettings.h"

//-------------------------------------------------------------------------------
DefineSingleton(GameSettings);

//-------------------------------------------------------------------------------
GameSettings::GameSettings()
:	m_maxEggs(0),
	m_maxEnemies(0),
	m_gridSize(0),
	m_tileSize(0),
	m_enemyDestroyDistance(0.f),
	m_enemyEscapeDistance(0.f),
	m_maxShield(0)
{
	TXMLReader reader("Assets/Data/Settings.xml", *this);
}

//-------------------------------------------------------------------------------
GameSettings::~GameSettings()
{
}

//-------------------------------------------------------------------------------
int GameSettings::GetMaxEggs() const
{
	return m_maxEggs;
}

//-------------------------------------------------------------------------------
int GameSettings::GetMaxEnemies() const
{
	return m_maxEnemies;
}

//-------------------------------------------------------------------------------
int GameSettings::GetMaxShield() const
{
	return m_maxShield;
}

//-------------------------------------------------------------------------------
int GameSettings::GetGridSize() const
{
	return m_gridSize;
}

//-------------------------------------------------------------------------------
int GameSettings::GetTileSize() const
{
	return m_tileSize;
}

//-------------------------------------------------------------------------------
float GameSettings::GetEnemyEscapeDistance() const
{
	return m_enemyEscapeDistance;
}

//-------------------------------------------------------------------------------
float GameSettings::GetEnemyDestroyDistance() const
{
	return m_enemyDestroyDistance;
}

//-------------------------------------------------------------------------------
TXMLObject* GameSettings::HandleLoadElement(const TString& strId, TDynamicSet<TDataVariant>& objects)
{
	return NULL;
}

//-------------------------------------------------------------------------------
void GameSettings::HandleLoadAttributes(TDynamicSet<TDataVariant>& objects)
{
	m_maxShield = TDataVariant::Find("maxShield", objects).GetInt();
	m_maxEggs = TDataVariant::Find("maxEggs", objects).GetInt();
	m_maxEnemies = TDataVariant::Find("maxEnemies", objects).GetInt();
	m_gridSize = TDataVariant::Find("gridSize", objects).GetInt();
	m_tileSize = TDataVariant::Find("tileSize", objects).GetInt();
	m_enemyDestroyDistance = TDataVariant::Find("enemyDestroyDistance", objects).GetFloat();
	m_enemyEscapeDistance = TDataVariant::Find("enemyEscapeDistance", objects).GetFloat();
}

//-------------------------------------------------------------------------------
void GameSettings::FinaliseLoad()
{
	// sanity check
	if ((m_gridSize * m_tileSize) > (int)TConfig::Get()->GetScreenWidth())
	{
		m_gridSize = (int)TConfig::Get()->GetScreenWidth() / m_tileSize;

		TDebugPrint(("[GameSettings::FinaliseLoad] Reducing grid size to %d", m_gridSize));
	}
}

//-------------------------------------------------------------------------------
void GameSettings::Write(TXMLWriter& writer)
{
}
