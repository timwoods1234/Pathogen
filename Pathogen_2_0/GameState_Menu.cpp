#include "GameState_Menu.h"

//-------------------------------------------------------------------------------
GameState_Menu::GameState_Menu()
{
	m_stateName = "Menu";
}

//-------------------------------------------------------------------------------
GameState_Menu::~GameState_Menu()
{
}

//-------------------------------------------------------------------------------
void GameState_Menu::OnEntry()
{
	TUIHelper::Hide("ConfirmNewGame");
	TUIHelper::Show("Menu");
}

//-------------------------------------------------------------------------------
void GameState_Menu::OnExit()
{
	TUIHelper::Hide("Menu");
	TUIHelper::Hide("ConfirmNewGame");
}