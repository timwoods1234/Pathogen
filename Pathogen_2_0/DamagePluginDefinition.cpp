#include "DamagePluginDefinition.h"
#include "DamagePlugin.h"

//-------------------------------------------------------------------------------
RegisterPluginType("Damage", DamagePluginDefinition, DamagePlugin);

//-------------------------------------------------------------------------------
DamagePluginDefinition::DamagePluginDefinition()
:	m_damage(0.f)
{
	m_name = "Damage";
}

//-------------------------------------------------------------------------------
DamagePluginDefinition::~DamagePluginDefinition()
{
}

//-------------------------------------------------------------------------------
float DamagePluginDefinition::GetDamage() const
{
	return m_damage;
}

//-------------------------------------------------------------------------------
unsigned int DamagePluginDefinition::GetNumTargets() const
{
	return m_allowedTargets.GetSize();
}

//-------------------------------------------------------------------------------
const TString& DamagePluginDefinition::GetTarget(unsigned int index) const
{
	if (index < m_allowedTargets.GetSize())
	{
		return m_allowedTargets[index];
	}

	return TString::GetEmptyString();
}

//-------------------------------------------------------------------------------
void DamagePluginDefinition::HandleLoadAttributes(TDynamicSet<TDataVariant>& objects)
{
	m_damage = TDataVariant::Find("damage", objects).GetFloat();
}

//-------------------------------------------------------------------------------
TXMLObject* DamagePluginDefinition::HandleLoadElement(const TString& strID, TDynamicSet<TDataVariant>& objects)
{
	if (strID == "Target")
	{
		TString target = TDataVariant::Find("plugin", objects).GetString();
		m_allowedTargets.Add(target);
	}

	return NULL;
}
