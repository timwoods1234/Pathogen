#include "AIController_RandomDirections.h"
#include "AISharedFunctions.h"
#include "MovementPlugin.h"
#include "AIPlugin.h"
#include "AIPluginDefinition.h"

//-------------------------------------------------------------------------------
AIController_RandomDirections::AIController_RandomDirections(AIPlugin* controller)
:	AIController_Base(controller)
{
}

//-------------------------------------------------------------------------------
AIController_RandomDirections::~AIController_RandomDirections()
{
}

//-------------------------------------------------------------------------------
void AIController_RandomDirections::Update(float elapsedTime)
{
	MovementPlugin* movementPlugin = static_cast<MovementPlugin*>(m_controller->GetEntity()->GetPlugin("Movement"));

	if (movementPlugin != NULL)
	{
		TVector2 direction = AISharedFunctions::GetRandomDirection();
		movementPlugin->SetDirection(direction);
	}
}
