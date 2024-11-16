#include "GameState_Options.h"

//-------------------------------------------------------------------------------
GameState_Options::GameState_Options()
{
	m_stateName = "Options";
}

//-------------------------------------------------------------------------------
GameState_Options::~GameState_Options()
{
}

//-------------------------------------------------------------------------------
void GameState_Options::OnEntry()
{
	TUIHelper::Show("Options");
}

//-------------------------------------------------------------------------------
void GameState_Options::OnExit()
{
	TUIHelper::Hide("Options");
}