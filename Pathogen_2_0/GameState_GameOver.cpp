#include "GameState_GameOver.h"

//-------------------------------------------------------------------------------
GameState_GameOver::GameState_GameOver()
{
	m_stateName = "GameOver";
}

//-------------------------------------------------------------------------------
GameState_GameOver::~GameState_GameOver()
{
}

//-------------------------------------------------------------------------------
void GameState_GameOver::OnEntry()
{
	TUIHelper::Show("GameOver");
}

//-------------------------------------------------------------------------------
void GameState_GameOver::OnExit()
{
	TUIHelper::Hide("GameOver");
}