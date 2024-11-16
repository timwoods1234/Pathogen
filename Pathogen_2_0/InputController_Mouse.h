#ifndef __INPUTCONTROLLER_MOUSE_H__
#define __INPUTCONTROLLER_MOUSE_H__

#ifndef __INPUTCONTROLLER_BASE_H__
#include "InputController_Base.h"
#endif

class InputController_Mouse : public InputController_Base
{
public:
	InputController_Mouse(InputPlugin* controller);

	// update movement and firing based on mouse input
	void Update(float elapsedTime);
};

#endif