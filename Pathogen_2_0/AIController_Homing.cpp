#include "AIController_Homing.h"
#include "AIPlugin.h"
#include "AIPluginDefinition.h"
#include "Level.h"
#include "MovementPlugin.h"

//-------------------------------------------------------------------------------
AIController_Homing::AIController_Homing(AIPlugin* controller)
:	AIController_Base(controller)
{
}

//-------------------------------------------------------------------------------
AIController_Homing::~AIController_Homing()
{
}

//-------------------------------------------------------------------------------
void AIController_Homing::Update(float elapsedTime)
{
	unsigned int numPlayers = Level::Get()->GetCount(EntityType::Player);

	if (numPlayers > 0)
	{
		const TEntity* player = Level::Get()->GetEntity(EntityType::Player, 0);

		if (player != NULL)
		{
			TEntity* entity = m_controller->GetEntity();

			TVector3 currentPosition = entity->GetPosition();
			TVector3 targetPosition = player->GetPosition();
			TVector3 difference = targetPosition - currentPosition;

			TVector2 direction(difference.x, difference.y);
			direction.Normalize();

			MovementPlugin* movementPlugin = static_cast<MovementPlugin*>(m_controller->GetEntity()->GetPlugin("Movement"));

			TASSERT((movementPlugin != NULL), "[AIController_Homing] Cannot find movement plugin");

			movementPlugin->SetDirection(direction);
		}
	}
}
