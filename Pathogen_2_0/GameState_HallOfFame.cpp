#include "GameState_HallOfFame.h"

//-------------------------------------------------------------------------------
GameState_HallOfFame::GameState_HallOfFame()
{
	m_stateName = "HallOfFame";
}

//-------------------------------------------------------------------------------
GameState_HallOfFame::~GameState_HallOfFame()
{
}

//-------------------------------------------------------------------------------
void GameState_HallOfFame::OnEntry()
{
	TUIHelper::Show("HallOfFame");
}

//-------------------------------------------------------------------------------
void GameState_HallOfFame::OnExit()
{
	TUIHelper::Hide("HallOfFame");
}