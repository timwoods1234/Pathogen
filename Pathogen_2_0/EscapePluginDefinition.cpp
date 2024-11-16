#include "EscapePlugin.h"
#include "EscapePluginDefinition.h"

//-------------------------------------------------------------------------------
RegisterPluginType("EscapePlugin", EscapePluginDefinition, EscapePlugin);

//-------------------------------------------------------------------------------
EscapePluginDefinition::EscapePluginDefinition()
{
	m_name = "EscapePlugin";
}

//-------------------------------------------------------------------------------
EscapePluginDefinition::~EscapePluginDefinition()
{
}

//-------------------------------------------------------------------------------
int EscapePluginDefinition::GetEscapeDamage() const
{
	return m_escapeDamage;
}

//-------------------------------------------------------------------------------
void EscapePluginDefinition::HandleLoadAttributes(TDynamicSet<TDataVariant>& objects)
{
	m_escapeDamage = TDataVariant::Find("escapeDamage", objects).GetInt();
}
