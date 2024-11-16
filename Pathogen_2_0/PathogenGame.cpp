#include "PathogenGame.h"

#include "GameState_Menu.h"
#include "GameState_HallOfFame.h"
#include "GameState_Playing.h"
#include "GameState_GameOver.h"
#include "GameState_Options.h"
#include "GameState_EnterHallOfFame.h"
#include "GameState_StartNextLevel.h"
#include "GameState_EditLevel.h"
#include "GameState_LevelCompleted.h"

#include "UIHallOfFame.h"
#include "UIMainMenu.h"
#include "UIOptions.h"
#include "UIPlayerStats.h"
#include "UILevelEditor.h"
#include "UIPlaying.h"
#include "UIGameOver.h"
#include "PauseStateUpdater.h"

#include "ColliderPlugin.h"
#include "SpritePlugin.h"
#include "AIPlugin.h"
#include "DamagePlugin.h"
#include "HealthPlugin.h"
#include "ShooterPlugin.h"
#include "InputPlugin.h"
#include "MovementPlugin.h"
#include "EscapePlugin.h"
#include "EggPlugin.h"
#include "ScorePlugin.h"
#include "EditorPlugin.h"
#include "PlayerPositionPlugin.h"
#include "EffectPlugin.h"
#include "PulseOverTimePlugin.h"
#include "DeathPlugin.h"

#include "Level.h"
#include "HallOfFame.h"
#include "PlayerStats.h"
#include "GameSettings.h"
#include "Options.h"
#include "MusicManager.h"

//-------------------------------------------------------------------------------
PathogenGame::PathogenGame()
{
	// TODO: put these into config too rather than app code
	TSimpleScene* simpleScene = TNew TSimpleScene();
	TLocator::RegisterScene(simpleScene);

	RegisterPlugins();

	CreateSingletons();

	CreateUIMappings();

	m_pauseStateUpdater = TNew PauseStateUpdater();

	CreateGameStates();
	
	if (TLocator::GetApplication()->GetCommandLineList()->Contains("editMode"))
	{
		TGameState::SwitchState("EditLevel");
	}
	else
	{
		TGameState::SwitchState("Menu");
	}
}

//-------------------------------------------------------------------------------
PathogenGame::~PathogenGame()
{
	TGameState::SwitchState("");

	for (unsigned int index = 0; index < m_gameStates.GetSize(); index++)
	{
		TSafeDelete(m_gameStates[index]);
	}

	TSafeDelete(m_pauseStateUpdater);

	for (unsigned int index = 0; index < m_uiControllers.GetSize(); index++)
	{
		TSafeDelete(m_uiControllers[index]);
	}

	DestroySingletons();

	TSceneInterface* scene = TLocator::GetScene();
	TSafeDelete(scene);
}

//-------------------------------------------------------------------------------
void PathogenGame::CreateSingletons()
{
	GameSettings::Create();
	Level::Create();
	HallOfFame::Create();
	PlayerStats::Create();
	Options::Create();
	MusicManager::Create();
}

//-------------------------------------------------------------------------------
void PathogenGame::DestroySingletons()
{
	MusicManager::Destroy();
	Options::Destroy();
	PlayerStats::Destroy();
	HallOfFame::Destroy();
	Level::Destroy();
	GameSettings::Destroy();
}

//-------------------------------------------------------------------------------
void PathogenGame::CreateGameStates()
{
	m_gameStates.Add(TNew GameState_Menu());
	m_gameStates.Add(TNew GameState_EnterHallOfFame());
	m_gameStates.Add(TNew GameState_HallOfFame());
	m_gameStates.Add(TNew GameState_Playing());
	m_gameStates.Add(TNew GameState_GameOver());
	m_gameStates.Add(TNew GameState_Options());
	m_gameStates.Add(TNew GameState_StartNextLevel());
	m_gameStates.Add(TNew GameState_EditLevel());
	m_gameStates.Add(TNew GameState_LevelCompleted());
}

//-------------------------------------------------------------------------------
void PathogenGame::CreateUIMappings()
{
	m_uiControllers.Add(TNew UIHallOfFame());
	m_uiControllers.Add(TNew UIMainMenu());
	m_uiControllers.Add(TNew UIOptions());
	m_uiControllers.Add(TNew UIPlayerStats());
	m_uiControllers.Add(TNew UILevelEditor());
	m_uiControllers.Add(TNew UIPlaying());
	m_uiControllers.Add(TNew UIGameOver());
}

//-------------------------------------------------------------------------------
void PathogenGame::RegisterPlugins()
{
	ColliderPlugin::Register();
	SpritePlugin::Register();
	MovementPlugin::Register();
	ShooterPlugin::Register();
	DamagePlugin::Register();
	HealthPlugin::Register();
	InputPlugin::Register();
	EscapePlugin::Register();
	EggPlugin::Register();
	ScorePlugin::Register();
	EditorPlugin::Register();
	AIPlugin::Register();
	PlayerPositionPlugin::Register();
	EffectPlugin::Register();
	PulseOverTimePlugin::Register();
	DeathPlugin::Register();
}
