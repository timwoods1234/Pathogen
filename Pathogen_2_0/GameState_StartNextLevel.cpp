#include "GameState_StartNextLevel.h"
#include "PlayerStats.h"
#include "Level.h"
#include "LevelList.h"
#include "LevelLoader.h"
#include "GameSettings.h"
#include "HallOfFame.h"

//-------------------------------------------------------------------------------
GameState_StartNextLevel::GameState_StartNextLevel()
{
	m_stateName = "StartNextLevel";

	m_levelList = TNew LevelList();
	m_levelLoader = TNew LevelLoader();
}

//-------------------------------------------------------------------------------
GameState_StartNextLevel::~GameState_StartNextLevel()
{
	TSafeDelete(m_levelList);
	TSafeDelete(m_levelLoader);
}

//-------------------------------------------------------------------------------
void GameState_StartNextLevel::OnEntry()
{
	unsigned int currentLevel = PlayerStats::Get()->GetCurrentLevel();
	unsigned int maxLevels = m_levelList->GetNumLevels();

	if (currentLevel < maxLevels)
	{
		const TString& nextLevelName = m_levelList->GetLevelName(currentLevel);

		m_levelLoader->Load(nextLevelName.GetPointer());

		int maxShield = GameSettings::Get()->GetMaxShield();
		PlayerStats::Get()->SetCurrentShield(maxShield);

		m_nextGameState = "Playing";

		PlayerStats::Get()->SetGameInProgress(true);
	}
	else
	{
		unsigned int currentScore = PlayerStats::Get()->GetCurrentScore();

		if (HallOfFame::Get()->IsScoreWorthy(currentScore))
		{
			m_nextGameState = "EnterHallOfFame";
		}
		else
		{
			m_nextGameState = "HallOfFame";
		}

		PlayerStats::Get()->SetGameInProgress(false);
	}

	TEventUpdate::Get()->Register(this, &GameState_StartNextLevel::OnUpdate);
}

//-------------------------------------------------------------------------------
void GameState_StartNextLevel::OnExit()
{
	TEventUpdate::Get()->Unregister(this, &GameState_StartNextLevel::OnUpdate);
}

//-------------------------------------------------------------------------------
void GameState_StartNextLevel::OnUpdate(float elapsedTime)
{
	TGameState::SwitchState(m_nextGameState.GetPointer());
}
