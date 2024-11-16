#ifndef __UIMAINMENU_H__
#define __UIMAINMENU_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class UIMainMenu : public TUIController
{
public:
	UIMainMenu();

	~UIMainMenu();

	void Resume(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void Start(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void HallOfFame(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void Options(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void Quit(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void ResumeAvailable(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void HideConfirmNewGame(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void ConfirmNewGame(const TUIVariableParameter* parameters, TUIVariableResult* result);

private:
	void StartNewGame();
};

#endif