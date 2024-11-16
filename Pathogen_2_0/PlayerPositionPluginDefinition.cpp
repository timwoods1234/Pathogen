#include "PlayerPositionPluginDefinition.h"
#include "PlayerPositionPlugin.h"

//-------------------------------------------------------------------------------
RegisterPluginType("PlayerPositionPlugin", PlayerPositionPluginDefinition, PlayerPositionPlugin);

//-------------------------------------------------------------------------------
PlayerPositionPluginDefinition::PlayerPositionPluginDefinition()
:	m_speed(0.f),
	m_circularDistance(0.f)
{
	m_name = "PlayerPositionPlugin";
}

//-------------------------------------------------------------------------------
PlayerPositionPluginDefinition::~PlayerPositionPluginDefinition()
{
}

//-------------------------------------------------------------------------------
float PlayerPositionPluginDefinition::GetSpeed() const
{
	return m_speed;
}

//-------------------------------------------------------------------------------
float PlayerPositionPluginDefinition::GetCircularDistance() const
{
	return m_circularDistance;
}

//-------------------------------------------------------------------------------
void PlayerPositionPluginDefinition::HandleLoadAttributes(TDynamicSet<TDataVariant>& objects)
{
	m_speed = TDataVariant::Find("speed", objects).GetFloat();
	m_circularDistance = TDataVariant::Find("distance", objects).GetFloat();
}