#include "GameState_EditLevel.h"
#include "LevelEditor.h"

//-------------------------------------------------------------------------------
GameState_EditLevel::GameState_EditLevel()
{
	m_stateName = "EditLevel";
}

//-------------------------------------------------------------------------------
GameState_EditLevel::~GameState_EditLevel()
{
}

//-------------------------------------------------------------------------------
void GameState_EditLevel::OnEntry()
{
	LevelEditor::Create();

	TUIHelper::Show("LevelEditor");
}

//-------------------------------------------------------------------------------
void GameState_EditLevel::OnExit()
{
	TUIHelper::Hide("LevelEditor");

	LevelEditor::Destroy();
}