#include "UIMainMenu.h"
#include "PlayerStats.h"

//-------------------------------------------------------------------------------
UIMainMenu::UIMainMenu()
{
	TUIMappingContainer::Get()->Register("Menu", "Resume", this, &UIMainMenu::Resume);
	TUIMappingContainer::Get()->Register("Menu", "NewGame", this, &UIMainMenu::Start);
	TUIMappingContainer::Get()->Register("Menu", "ViewHallOfFame", this, &UIMainMenu::HallOfFame);
	TUIMappingContainer::Get()->Register("Menu", "Options", this, &UIMainMenu::Options);
	TUIMappingContainer::Get()->Register("Menu", "Quit", this, &UIMainMenu::Quit);
	TUIMappingContainer::Get()->Register("Menu", "HideConfirmNewGame", this, &UIMainMenu::HideConfirmNewGame);
	TUIMappingContainer::Get()->Register("Menu", "ConfirmNewGame", this, &UIMainMenu::ConfirmNewGame);

	TUIMappingContainer::Get()->Register("Menu", "ResumeAvailable", this, &UIMainMenu::ResumeAvailable);
}

//-------------------------------------------------------------------------------
UIMainMenu::~UIMainMenu()
{
	TUIMappingContainer::Get()->UnregisterMappings("Menu");
}

//-------------------------------------------------------------------------------
void UIMainMenu::Resume(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	TGameState::SwitchState("Playing");
}

//-------------------------------------------------------------------------------
void UIMainMenu::Start(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	if (PlayerStats::Get()->GetGameInProgress())
	{
		TUIHelper::Show("ConfirmNewGame");
		TUIHelper::Hide("Menu");
	}
	else
	{
		StartNewGame();
	}
}

//-------------------------------------------------------------------------------
void UIMainMenu::HallOfFame(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	TGameState::SwitchState("HallOfFame");
}

//-------------------------------------------------------------------------------
void UIMainMenu::Options(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	TGameState::SwitchState("Options");
}

//-------------------------------------------------------------------------------
void UIMainMenu::Quit(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	TLocator::GetApplication()->Quit();
}

//-------------------------------------------------------------------------------
void UIMainMenu::ResumeAvailable(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	if (PlayerStats::Get()->GetGameInProgress())
	{
		result->stringValue = "True";
	}
	else
	{
		result->stringValue = "False";
	}
}

//-------------------------------------------------------------------------------
void UIMainMenu::HideConfirmNewGame(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	TUIHelper::Hide("ConfirmNewGame");
	TUIHelper::Show("Menu");
}

//-------------------------------------------------------------------------------
void UIMainMenu::ConfirmNewGame(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	StartNewGame();
}

//-------------------------------------------------------------------------------
void UIMainMenu::StartNewGame()
{
	// TODO: store in settings
	int defaultLives = 3;

	PlayerStats::Get()->SetCurrentLevel(1);
	PlayerStats::Get()->SetCurrentLives(defaultLives);
	PlayerStats::Get()->SetCurrentScore(0);

	TGameState::SwitchState("StartNextLevel");
}