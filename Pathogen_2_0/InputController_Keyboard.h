#ifndef __INPUTCONTROLLER_KEYBOARD_H__
#define __INPUTCONTROLLER_KEYBOARD_H__

#ifndef __INPUTCONTROLLER_BASE_H__
#include "InputController_Base.h"
#endif

class InputController_Keyboard : public InputController_Base
{
public:
	InputController_Keyboard(InputPlugin* controller);

	// update movement and firing based on mouse input
	void Update(float elapsedTime);
};

#endif