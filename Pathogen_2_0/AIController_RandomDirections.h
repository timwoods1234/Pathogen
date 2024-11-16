#ifndef __AICONTROLLER_RANDOMDIRECTIONS_H__
#define __AICONTROLLER_RANDOMDIRECTIONS_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

#ifndef __AICONTROLLER_BASE_H__
#include "AIController_Base.h"
#endif

class AIController_RandomDirections : public AIController_Base
{
public:
	AIController_RandomDirections(AIPlugin* controller);

	~AIController_RandomDirections();

	void Update(float elapsedTime);
};

#endif
