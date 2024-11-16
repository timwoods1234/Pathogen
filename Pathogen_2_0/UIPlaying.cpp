#include "UIPlaying.h"

//-------------------------------------------------------------------------------
UIPlaying::UIPlaying()
{
	TUIMappingContainer::Get()->Register("Playing", "Menu", this, &UIPlaying::Menu);
}

//-------------------------------------------------------------------------------
UIPlaying::~UIPlaying()
{
	TUIMappingContainer::Get()->UnregisterMappings("Playing");
}

//-------------------------------------------------------------------------------
void UIPlaying::Menu(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	TGameState::SwitchState("Menu");
}
