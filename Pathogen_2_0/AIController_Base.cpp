#include "AIController_Base.h"

//-------------------------------------------------------------------------------
AIController_Base::AIController_Base(AIPlugin* controller)
:	m_controller(controller)
{
}

//-------------------------------------------------------------------------------
AIController_Base::~AIController_Base()
{
}

//-------------------------------------------------------------------------------
void AIController_Base::Update(float elapsedTime)
{
}
