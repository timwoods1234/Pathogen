#include "UIHallOfFame.h"
#include "HallOfFame.h"
#include "PlayerStats.h"

//-------------------------------------------------------------------------------
UIHallOfFame::UIHallOfFame()
{
	TUIMappingContainer::Get()->Register("HallOfFame", "GetNameAtIndex", this, &UIHallOfFame::GetNameAtIndex);
	TUIMappingContainer::Get()->Register("HallOfFame", "GetScoreAtIndex", this, &UIHallOfFame::GetScoreAtIndex);
	TUIMappingContainer::Get()->Register("HallOfFame", "UpdatePlayerName", this, &UIHallOfFame::UpdatePlayerName);
	TUIMappingContainer::Get()->Register("HallOfFame", "ConfirmNameEntry", this, &UIHallOfFame::ConfirmNameEntry);
	TUIMappingContainer::Get()->Register("HallOfFame", "GoToMenu", this, &UIHallOfFame::GoToMenu);
}

//-------------------------------------------------------------------------------
UIHallOfFame::~UIHallOfFame()
{
	TUIMappingContainer::Get()->UnregisterMappings("HallOfFame");
}

//-------------------------------------------------------------------------------
void UIHallOfFame::GetNameAtIndex(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	unsigned int index = (unsigned int)parameters->intValue;

	const HallOfFameEntry* entry = HallOfFame::Get()->GetEntry(index);

	if (entry != NULL)
	{
		result->stringValue = entry->GetPlayerName();
	}
}

//-------------------------------------------------------------------------------
void UIHallOfFame::GetScoreAtIndex(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	unsigned int index = (unsigned int)parameters->intValue;

	const HallOfFameEntry* entry = HallOfFame::Get()->GetEntry(index);

	if (entry != NULL)
	{
		result->stringValue = TString::Format("%d", entry->GetTotalScore());
	}
}

//-------------------------------------------------------------------------------
void UIHallOfFame::UpdatePlayerName(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	if (parameters != NULL)
	{
		HallOfFame::Get()->SetCurrentName(parameters->stringValue);
	}
	else if (result != NULL)
	{
		result->stringValue = HallOfFame::Get()->GetCurrentName();
	}
}

//-------------------------------------------------------------------------------
void UIHallOfFame::ConfirmNameEntry(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	HallOfFame::Get()->AddEntry(HallOfFame::Get()->GetCurrentName(), PlayerStats::Get()->GetCurrentScore());

	HallOfFame::Get()->SortEntries();

	HallOfFame::Get()->Save();

	TGameState::SwitchState("HallOfFame");
}

//-------------------------------------------------------------------------------
void UIHallOfFame::GoToMenu(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	TGameState::SwitchState("Menu");
}