#include "InputPluginDefinition.h"
#include "InputPlugin.h"

//-------------------------------------------------------------------------------
RegisterPluginType("Input", InputPluginDefinition, InputPlugin);

//-------------------------------------------------------------------------------
InputPluginDefinition::InputPluginDefinition()
{
	m_name = "Input";
}

//-------------------------------------------------------------------------------
InputPluginDefinition::~InputPluginDefinition()
{
}

//-------------------------------------------------------------------------------
long InputPluginDefinition::GetDeadzone() const
{
	return m_deadZone;
}

//-------------------------------------------------------------------------------
void InputPluginDefinition::HandleLoadAttributes(TDynamicSet<TDataVariant>& objects)
{
	m_deadZone = TDataVariant::Find("deadzone", objects).GetInt();
}
