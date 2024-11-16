#ifndef __INPUTCONTROLLER_BASE_H__
#define __INPUTCONTROLLER_BASE_H__

class InputPlugin;
class ShooterPlugin;
class PlayerPositionPlugin;

class InputController_Base
{
public:
	InputController_Base(InputPlugin* controller);

	virtual ~InputController_Base();

	virtual void Update(float elapsedTime) = 0;

protected:
	PlayerPositionPlugin* m_playerPositionPlugin;
	ShooterPlugin* m_shooterPlugin;
};

#endif
