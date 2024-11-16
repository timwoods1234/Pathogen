#ifndef __UIPLAYING_H__
#define __UIPLAYING_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class UIPlaying : public TUIController
{
public:
	UIPlaying();

	~UIPlaying();

	void Menu(const TUIVariableParameter* parameters, TUIVariableResult* result);
};

#endif