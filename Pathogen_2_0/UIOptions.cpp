#include "UIOptions.h"
#include "Options.h"

//-------------------------------------------------------------------------------
UIOptions::UIOptions()
{
	TUIMappingContainer::Get()->Register("Options", "GetMusicVolume", this, &UIOptions::GetMusicVolume);
	TUIMappingContainer::Get()->Register("Options", "GetSFXVolume", this, &UIOptions::GetSFXVolume);
	TUIMappingContainer::Get()->Register("Options", "GetMasterVolume", this, &UIOptions::GetMasterVolume);
	TUIMappingContainer::Get()->Register("Options", "SetMusicVolume", this, &UIOptions::SetMusicVolume);
	TUIMappingContainer::Get()->Register("Options", "SetSFXVolume", this, &UIOptions::SetSFXVolume);
	TUIMappingContainer::Get()->Register("Options", "SetMasterVolume", this, &UIOptions::SetMasterVolume);

	TUIMappingContainer::Get()->Register("Options", "GetAutoFireState", this, &UIOptions::GetAutoFireState);
	TUIMappingContainer::Get()->Register("Options", "ToggleAutoFire", this, &UIOptions::ToggleAutoFire);

	TUIMappingContainer::Get()->Register("Options", "TestSFXVolume", this, &UIOptions::TestSFXVolume);
	TUIMappingContainer::Get()->Register("Options", "Confirm", this, &UIOptions::ConfirmOptions);
	
	m_volCheckSound = TSound::Acquire("volcheck");
}

//-------------------------------------------------------------------------------
UIOptions::~UIOptions()
{
	TSound::Release(m_volCheckSound);

	TUIMappingContainer::Get()->UnregisterMappings("Options");
}

//-------------------------------------------------------------------------------
void UIOptions::TestSFXVolume(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	if (m_volCheckSound != NULL)
	{
		m_volCheckSound->Play();
	}
}

//-------------------------------------------------------------------------------
void UIOptions::ConfirmOptions(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	Options::Get()->Save();
	TGameState::SwitchState("Menu");
}

//-------------------------------------------------------------------------------
void UIOptions::GetMusicVolume(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	result->floatValue = TLocator::GetAudio()->GetVolume(TSoundChannel::TSoundChannel_Music);
}

//-------------------------------------------------------------------------------
void UIOptions::GetSFXVolume(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	result->floatValue = TLocator::GetAudio()->GetVolume(TSoundChannel::TSoundChannel_SFX);
}

//-------------------------------------------------------------------------------
void UIOptions::GetMasterVolume(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	result->floatValue = TLocator::GetAudio()->GetVolume(TSoundChannel::TSoundChannel_Master);
}

//-------------------------------------------------------------------------------
void UIOptions::SetMusicVolume(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	TLocator::GetAudio()->SetVolume(parameters->floatValue, TSoundChannel::TSoundChannel_Music);
}

//-------------------------------------------------------------------------------
void UIOptions::SetSFXVolume(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	TLocator::GetAudio()->SetVolume(parameters->floatValue, TSoundChannel::TSoundChannel_SFX);
}

//-------------------------------------------------------------------------------
void UIOptions::SetMasterVolume(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	TLocator::GetAudio()->SetVolume(parameters->floatValue, TSoundChannel::TSoundChannel_Master);
}

//-------------------------------------------------------------------------------
void UIOptions::GetAutoFireState(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	bool autoFire = Options::Get()->GetAutoFire();

	result->stringValue = autoFire ? "Enabled" : "Disabled";
}

//-------------------------------------------------------------------------------
void UIOptions::ToggleAutoFire(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	bool autoFire = Options::Get()->GetAutoFire();

	Options::Get()->SetAutoFire(!autoFire);
}
