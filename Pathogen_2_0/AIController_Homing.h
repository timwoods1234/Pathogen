#ifndef __AICONTROLLER_HOMING_H__
#define __AICONTROLLER_HOMING_H__

#ifndef __AICONTROLLER_BASE_H__
#include "AIController_Base.h"
#endif

class MovementPlugin;

class AIController_Homing : public AIController_Base
{
public:
	AIController_Homing(AIPlugin* controller);

	~AIController_Homing();

	void Update(float elapsedTime);
};

#endif
