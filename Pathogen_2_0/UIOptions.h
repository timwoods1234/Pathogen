#ifndef __UIOPTIONS_H__
#define __UIOPTIONS_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class UIOptions : public TUIController
{
public:
	UIOptions();

	~UIOptions();

	void GetMusicVolume(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void GetSFXVolume(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void GetMasterVolume(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void SetMusicVolume(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void SetSFXVolume(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void SetMasterVolume(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void TestSFXVolume(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void ConfirmOptions(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void GetAutoFireState(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void ToggleAutoFire(const TUIVariableParameter* parameters, TUIVariableResult* result);

private:
	TSound* m_volCheckSound;
};

#endif
