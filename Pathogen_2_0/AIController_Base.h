#ifndef __AICONTROLLER_BASE_H__
#define __AICONTROLLER_BASE_H__

class AIPlugin;

class AIController_Base
{
public:
	AIController_Base(AIPlugin* controller);

	virtual ~AIController_Base();

	virtual void Update(float elapsedTime);

protected:
	AIPlugin* m_controller;
};

#endif
