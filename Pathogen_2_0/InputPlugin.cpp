#include "TEngine.h"
#include "InputPlugin.h"
#include "InputController_Keyboard.h"
#include "InputController_Mouse.h"

//-------------------------------------------------------------------------------
InputPlugin::InputPlugin(TEntity* entity, TPluginDefinition* definition)
:	TPlugin(entity, definition)
{
	m_inputControllers.Add(TNew InputController_Keyboard(this));
	//m_inputControllers.Add(TNew InputController_Mouse(this));

	TEventUpdate::Get()->Register(this, &InputPlugin::Update);
}

//-------------------------------------------------------------------------------
InputPlugin::~InputPlugin()
{
	TEventUpdate::Get()->Unregister(this, &InputPlugin::Update);

	for (unsigned int index = 0; index < m_inputControllers.GetSize(); index++)
	{
		TSafeDelete(m_inputControllers[index]);
	}
}

//-------------------------------------------------------------------------------
void InputPlugin::Update(float elapsedTime)
{
	for (unsigned int index = 0; index < m_inputControllers.GetSize(); index++)
	{
		m_inputControllers[index]->Update(elapsedTime);
	}
}
