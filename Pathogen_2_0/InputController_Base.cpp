#include "InputController_Base.h"
#include "PlayerPositionPlugin.h"
#include "ShooterPlugin.h"
#include "InputPlugin.h"

//-------------------------------------------------------------------------------
InputController_Base::InputController_Base(InputPlugin* controller)
{
	m_playerPositionPlugin = static_cast<PlayerPositionPlugin*>(controller->GetEntity()->GetPlugin("PlayerPositionPlugin"));
	m_shooterPlugin = static_cast<ShooterPlugin*>(controller->GetEntity()->GetPlugin("Shooter"));

	if (m_playerPositionPlugin == NULL)
	{
		TDebugPrint(("[InputController_Base] No player position plugin found"));
	}

	if (m_shooterPlugin == NULL)
	{
		TDebugPrint(("[InputController_Base] No shooter plugin found"));
	}
}

//-------------------------------------------------------------------------------
InputController_Base::~InputController_Base()
{
}
