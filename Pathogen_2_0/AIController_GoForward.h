#ifndef __AICONTROLLER_GOFORWARD_H__
#define __AICONTROLLER_GOFORWARD_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

#ifndef __AICONTROLLER_BASE_H__
#include "AIController_Base.h"
#endif

class AIController_GoForward : public AIController_Base
{
public:
	AIController_GoForward(AIPlugin* controller);

	~AIController_GoForward();
};

#endif
