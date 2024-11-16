#ifndef __UIPLAYERSTATS_H__
#define __UIPLAYERSTATS_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class UIPlayerStats : public TUIController
{
public:
	UIPlayerStats();

	~UIPlayerStats();

	void GetScore(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void GetNumLives(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void GetLevel(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void GetShield(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void GetShieldRelative(const TUIVariableParameter* parameters, TUIVariableResult* result);
};

#endif
