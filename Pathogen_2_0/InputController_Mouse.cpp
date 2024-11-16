#include "TEngine.h"
#include "InputController_Mouse.h"
#include "PlayerPositionPlugin.h"

//-------------------------------------------------------------------------------
InputController_Mouse::InputController_Mouse(InputPlugin* controller)
:	InputController_Base(controller)
{
}

//-------------------------------------------------------------------------------
void InputController_Mouse::Update(float elapsedTime)
{
	if (TLocator::GetInput()->IsDown(TINPUT_MOUSE_LEFT))
	{
		// tell shooter to fire
	}

	TVector2 center = TVector2(TConfig::Get()->GetScreenWidth() * 0.5f, TConfig::Get()->GetScreenHeight() * 0.5f);
	TVector2 playerPosition = center;

	TLocator::GetInput()->GetMousePosition(playerPosition);

	bool above = playerPosition.y < center.y;
	bool right = playerPosition.x > center.x;
	bool increaseAngle = false;
	bool decreaseAngle = false;

	long mouseAxisX = TLocator::GetInput()->GetXAmt();
	long mouseAxisY = TLocator::GetInput()->GetYAmt();

	if (above)
	{
		if (right)
		{
			if (mouseAxisX > 0 || mouseAxisY < 0)
			{
				increaseAngle = true;
			}
			else if (mouseAxisX < 0 || mouseAxisY > 0)
			{
				decreaseAngle = true;
			}
		}
		else
		{
			if (mouseAxisX < 0 || mouseAxisY < 0)
			{
				increaseAngle = true;
			}
			else if (mouseAxisX > 0 || mouseAxisY < 0)
			{
				decreaseAngle = true;
			}
		}
	}
	else // below
	{
		if (right)
		{
			if (mouseAxisX < 0 || mouseAxisY > 0)
			{
				increaseAngle = true;
			}
			else if (mouseAxisX > 0 || mouseAxisY < 0)
			{
				decreaseAngle = true;
			}
		}
		else
		{
			if (mouseAxisX < 0 || mouseAxisY < 0)
			{
				increaseAngle = true;
			}
			else if (mouseAxisX > 0 || mouseAxisY > 0)
			{
				decreaseAngle = true;
			}
		}
	}

	if (increaseAngle)
	{
		m_playerPositionPlugin->IncreaseAngle();
	}
	else if (decreaseAngle)
	{
		m_playerPositionPlugin->DecreaseAngle();
	}

	TDebugPrint(("x: %d, y: %d", mouseAxisX, mouseAxisY));
}
