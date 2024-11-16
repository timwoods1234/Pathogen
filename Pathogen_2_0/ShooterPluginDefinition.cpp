#include "ShooterPluginDefinition.h"
#include "ShooterPlugin.h"

//-------------------------------------------------------------------------------
RegisterPluginType("Shooter", ShooterPluginDefinition, ShooterPlugin);

//-------------------------------------------------------------------------------
ShooterPluginDefinition::ShooterPluginDefinition()
:	m_timeBetweenAttacks(1.f)
{
	m_name = "Shooter";
}

//-------------------------------------------------------------------------------
float ShooterPluginDefinition::GetTimeBetweenAttacks() const
{
	return m_timeBetweenAttacks;
}

//-------------------------------------------------------------------------------
const TString& ShooterPluginDefinition::GetFireSound() const
{
	return m_fireSound;
}

//-------------------------------------------------------------------------------
void ShooterPluginDefinition::HandleLoadAttributes(TDynamicSet<TDataVariant>& objects)
{
	m_fireSound = TDataVariant::Find("fireSound", objects).GetString();
	m_timeBetweenAttacks = TDataVariant::Find("timeBetweenAttacks", objects).GetFloat();

	m_timeBetweenAttacks = TClamp(m_timeBetweenAttacks, 0.01f, 10.f);
}
