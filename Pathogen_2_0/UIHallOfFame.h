#ifndef __UIHALLOFFAME_H__
#define __UIHALLOFFAME_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class UIHallOfFame : public TUIController
{
public:
	UIHallOfFame();

	~UIHallOfFame();

	void GetNameAtIndex(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void GetScoreAtIndex(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void UpdatePlayerName(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void ConfirmNameEntry(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void GoToMenu(const TUIVariableParameter* parameters, TUIVariableResult* result);
};

#endif
