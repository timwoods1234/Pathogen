#include "MovementPluginDefinition.h"
#include "MovementPlugin.h"

//-------------------------------------------------------------------------------
RegisterPluginType("Movement", MovementPluginDefinition, MovementPlugin);

//-------------------------------------------------------------------------------
MovementPluginDefinition::MovementPluginDefinition()
:	m_speed(0.f)
{
	m_name = "Movement";
}

//-------------------------------------------------------------------------------
float MovementPluginDefinition::GetSpeed() const
{
	return m_speed;
}

//-------------------------------------------------------------------------------
void MovementPluginDefinition::HandleLoadAttributes(TDynamicSet<TDataVariant>& objects)
{
	m_speed = TDataVariant::Find("speed", objects).GetFloat();
}