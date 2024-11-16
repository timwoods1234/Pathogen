#include "GameState_EnterHallOfFame.h"
#include "HallOfFame.h"
#include "PlayerStats.h"

//-------------------------------------------------------------------------------
GameState_EnterHallOfFame::GameState_EnterHallOfFame()
{
	m_stateName = "EnterHallOfFame";
}

//-------------------------------------------------------------------------------
GameState_EnterHallOfFame::~GameState_EnterHallOfFame()
{
}

//-------------------------------------------------------------------------------
void GameState_EnterHallOfFame::OnEntry()
{
	HallOfFame::Get()->SetCurrentName(TString::GetEmptyString());

	TUIHelper::Show("EnterHallOfFame");
}

//-------------------------------------------------------------------------------
void GameState_EnterHallOfFame::OnExit()
{
	TUIHelper::Hide("EnterHallOfFame");
}
