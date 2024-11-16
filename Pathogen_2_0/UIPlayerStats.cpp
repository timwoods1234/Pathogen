#include "UIPlayerStats.h"
#include "PlayerStats.h"
#include "GameSettings.h"

//-------------------------------------------------------------------------------
UIPlayerStats::UIPlayerStats()
{
	TUIMappingContainer::Get()->Register("PlayerStats", "GetScore", this, &UIPlayerStats::GetScore);
	TUIMappingContainer::Get()->Register("PlayerStats", "GetNumLives", this, &UIPlayerStats::GetNumLives);
	TUIMappingContainer::Get()->Register("PlayerStats", "GetLevel", this, &UIPlayerStats::GetLevel);
	TUIMappingContainer::Get()->Register("PlayerStats", "GetContinues", this, &UIPlayerStats::GetLevel);
	TUIMappingContainer::Get()->Register("PlayerStats", "GetShield", this, &UIPlayerStats::GetShield);
	TUIMappingContainer::Get()->Register("PlayerStats", "GetShieldRelative", this, &UIPlayerStats::GetShieldRelative);
}

//-------------------------------------------------------------------------------
UIPlayerStats::~UIPlayerStats()
{
	TUIMappingContainer::Get()->UnregisterMappings("PlayerStats");
}

//-------------------------------------------------------------------------------
void UIPlayerStats::GetScore(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	int score = PlayerStats::Get()->GetCurrentScore();
	result->stringValue = TString::Format("%d", score);
}

//-------------------------------------------------------------------------------
void UIPlayerStats::GetNumLives(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	int lives = PlayerStats::Get()->GetCurrentLives();
	result->stringValue = TString::Format("%d", lives);
}

//-------------------------------------------------------------------------------
void UIPlayerStats::GetLevel(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	int level = PlayerStats::Get()->GetCurrentLevel();
	result->stringValue = TString::Format("%d", level);
}

//-------------------------------------------------------------------------------
void UIPlayerStats::GetShield(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	int shield = PlayerStats::Get()->GetCurrentShield();
	result->stringValue = TString::Format("%d", shield);
}

//-------------------------------------------------------------------------------
void UIPlayerStats::GetShieldRelative(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	int currentShield = PlayerStats::Get()->GetCurrentShield();
	int maxShield = GameSettings::Get()->GetMaxShield();

	result->floatValue = (float)currentShield / (float)maxShield;
}
