#include "DeathPluginDefinition.h"
#include "DeathPlugin.h"

//-------------------------------------------------------------------------------
RegisterPluginType("Death", DeathPluginDefinition, DeathPlugin);

//-------------------------------------------------------------------------------
DeathPluginDefinition::DeathPluginDefinition()
{
	m_name = "Death";
}

//-------------------------------------------------------------------------------
DeathPluginDefinition::~DeathPluginDefinition()
{
}

//-------------------------------------------------------------------------------
const TString& DeathPluginDefinition::GetDeathParticle() const
{
	return m_deathParticle;
}

//-------------------------------------------------------------------------------
const TString& DeathPluginDefinition::GetDeathSound() const
{
	return m_deathSound;
}

//-------------------------------------------------------------------------------
void DeathPluginDefinition::HandleLoadAttributes(TDynamicSet<TDataVariant>& objects)
{
	m_deathParticle = TDataVariant::Find("deathParticle", objects).GetString();
	m_deathSound = TDataVariant::Find("deathSound", objects).GetString();
}
