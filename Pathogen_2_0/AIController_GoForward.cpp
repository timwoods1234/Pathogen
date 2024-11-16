#include "AIController_GoForward.h"
#include "AIPlugin.h"
#include "AISharedFunctions.h"
#include "MovementPlugin.h"

//-------------------------------------------------------------------------------
AIController_GoForward::AIController_GoForward(AIPlugin* controller)
:	AIController_Base(controller)
{
	MovementPlugin* movementPlugin = static_cast<MovementPlugin*>(controller->GetEntity()->GetPlugin("Movement"));

	if (movementPlugin != NULL)
	{
		TVector2 direction = AISharedFunctions::GetRandomDirection();
		movementPlugin->SetDirection(direction);
	}
}

//-------------------------------------------------------------------------------
AIController_GoForward::~AIController_GoForward()
{
}
