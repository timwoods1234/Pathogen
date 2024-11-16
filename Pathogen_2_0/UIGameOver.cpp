#include "UIGameOver.h"
#include "PlayerStats.h"
#include "HallOfFame.h"

//-------------------------------------------------------------------------------
UIGameOver::UIGameOver()
{
	TUIMappingContainer::Get()->Register("GameOver", "Quit", this, &UIGameOver::Quit);
}

//-------------------------------------------------------------------------------
UIGameOver::~UIGameOver()
{
	TUIMappingContainer::Get()->UnregisterMappings("GameOver");
}

//-------------------------------------------------------------------------------
void UIGameOver::Quit(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	int score = PlayerStats::Get()->GetCurrentScore();

	if (HallOfFame::Get()->IsScoreWorthy(score))
	{
		TGameState::SwitchState("EnterHallOfFame");
	}
	else
	{
		TGameState::SwitchState("HallOfFame");
	}
}