#include "HealthPluginDefinition.h"
#include "HealthPlugin.h"

//-------------------------------------------------------------------------------
RegisterPluginType("Health", HealthPluginDefinition, HealthPlugin);

//-------------------------------------------------------------------------------
HealthPluginDefinition::HealthPluginDefinition()
{
	m_name = "Health";
}

//-------------------------------------------------------------------------------
HealthPluginDefinition::~HealthPluginDefinition()
{
}

//-------------------------------------------------------------------------------
float HealthPluginDefinition::GetMaxHealth() const
{
	return m_maxHealth;
}

//-------------------------------------------------------------------------------
float HealthPluginDefinition::GetInvulnerableTime() const
{
	return m_invulnerableTime;
}

//-------------------------------------------------------------------------------
void HealthPluginDefinition::HandleLoadAttributes(TDynamicSet<TDataVariant>& objects)
{
	m_maxHealth = TDataVariant::Find("maxHealth", objects).GetFloat();
	m_invulnerableTime = TDataVariant::Find("invulTime", objects).GetFloat();
}
