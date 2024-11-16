#ifndef __UIGAMEOVER_H__
#define __UIGAMEOVER_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class UIGameOver : public TUIController
{
public:
	UIGameOver();

	~UIGameOver();

	void Quit(const TUIVariableParameter* parameters, TUIVariableResult* result);
};

#endif
