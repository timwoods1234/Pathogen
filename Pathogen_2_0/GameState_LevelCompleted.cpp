#include "GameState_LevelCompleted.h"
#include "PlayerStats.h"

//-------------------------------------------------------------------------------
GameState_LevelCompleted::GameState_LevelCompleted()
{
	m_stateName = "LevelCompleted";
}

//-------------------------------------------------------------------------------
GameState_LevelCompleted::~GameState_LevelCompleted()
{
}

//-------------------------------------------------------------------------------
void GameState_LevelCompleted::OnUpdate(float elapsedTime)
{
	float currentTime = TLocator::GetTimer()->GetAppTime();

	if (currentTime - m_entryTime > c_stateDuration)
	{
		int nextLevel = PlayerStats::Get()->GetCurrentLevel() + 1;
		PlayerStats::Get()->SetCurrentLevel(nextLevel);

		TGameState::SwitchState("StartNextLevel");
	}
}

//-------------------------------------------------------------------------------
void GameState_LevelCompleted::OnEntry()
{
	m_entryTime = TLocator::GetTimer()->GetAppTime();

	TEventUpdate::Get()->Register(this, &GameState_LevelCompleted::OnUpdate);

	TUIHelper::Show("LevelCompleted");
}

//-------------------------------------------------------------------------------
void GameState_LevelCompleted::OnExit()
{
	TUIHelper::Hide("LevelCompleted");

	TEventUpdate::Get()->Unregister(this, &GameState_LevelCompleted::OnUpdate);
}
