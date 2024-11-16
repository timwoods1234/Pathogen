#include "GameState_Playing.h"
#include "Level.h"
#include "PlayerStats.h"

//-------------------------------------------------------------------------------
GameState_Playing::GameState_Playing()
:	m_background(NULL)
{
	m_stateName = "Playing";

	TEntityDefinition* backgroundDefinition = TEntityDefinition::Acquire("Background");
	m_background = TNew TEntity(backgroundDefinition);
	TEntityDefinition::Release(backgroundDefinition);
}

//-------------------------------------------------------------------------------
GameState_Playing::~GameState_Playing()
{
	TSafeDelete(m_background);
}

//-------------------------------------------------------------------------------
void GameState_Playing::OnUpdate(float elapsedTime)
{
	TSceneInterface* scene = TLocator::GetScene();

	if (scene != NULL)
	{
		Level::Get()->collisionsBeingPerformed = true;
		scene->PerformCollisionDetection();
		Level::Get()->collisionsBeingPerformed = false;
	}

	Level::Get()->RemoveDeadEntities();

	CheckPlayerState();

	CheckShieldState();

	CheckVictoryState();

	if (TLocator::GetInput()->IsPressed(TINPUT_ESCAPE))
	{
		TGameState::SwitchState("Menu");
	}
}

//-------------------------------------------------------------------------------
void GameState_Playing::OnEntry()
{
	TUIHelper::Show("Playing");

	TEventUpdate::Get()->Register(this, &GameState_Playing::OnUpdate);
}

//-------------------------------------------------------------------------------
void GameState_Playing::OnExit()
{
	TEventUpdate::Get()->Unregister(this, &GameState_Playing::OnUpdate);

	TUIHelper::Hide("Playing");
}

//-------------------------------------------------------------------------------
void GameState_Playing::CheckShieldState()
{
	int currentShield = PlayerStats::Get()->GetCurrentShield();

	if (currentShield <= 0)
	{
		TGameState::SwitchState("GameOver");
	}
}

//-------------------------------------------------------------------------------
void GameState_Playing::CheckVictoryState()
{
	bool nextLevel = false;

	unsigned int numEggs = Level::Get()->GetCount(EntityType::Egg);
	unsigned int numEnemies = Level::Get()->GetCount(EntityType::Enemy);

	if ((numEnemies + numEggs) == 0)
	{
		nextLevel = true;
	}

#if defined(DEBUG) | defined(_DEBUG)
	if (TLocator::GetInput()->IsReleased(TINPUT_BACKSPACE))
	{
		nextLevel = true;
	}
#endif

	if (nextLevel)
	{
		TGameState::SwitchState("LevelCompleted");
	}
}

//-------------------------------------------------------------------------------
void GameState_Playing::CheckPlayerState()
{
	unsigned int numPlayers = Level::Get()->GetCount(EntityType::Player);

	if (numPlayers == 0)
	{
		int numLives = PlayerStats::Get()->GetCurrentLives();

		if (numLives > 0)
		{
			numLives--;

			Level::Get()->AddPlayer();

			PlayerStats::Get()->SetCurrentLives(numLives);
		}
		else
		{
			TGameState::SwitchState("GameOver");
		}
	}
}
