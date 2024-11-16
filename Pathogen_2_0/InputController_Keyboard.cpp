#include "TEngine.h"
#include "InputController_Keyboard.h"
#include "PlayerPositionPlugin.h"
#include "ShooterPlugin.h"

//-------------------------------------------------------------------------------
InputController_Keyboard::InputController_Keyboard(InputPlugin* controller)
:	InputController_Base(controller)
{
}

//-------------------------------------------------------------------------------
void InputController_Keyboard::Update(float elapsedTime)
{
	if (TLocator::GetInput()->IsDown(TINPUT_LEFT))
	{
		m_playerPositionPlugin->IncreaseAngle();
	}
	else if (TLocator::GetInput()->IsDown(TINPUT_RIGHT))
	{
		m_playerPositionPlugin->DecreaseAngle();
	}

	if (TLocator::GetInput()->IsDown(TINPUT_SPACE))
	{
		if (m_shooterPlugin != NULL)
		{
			m_shooterPlugin->SetFiring(true);
		}
	}
}