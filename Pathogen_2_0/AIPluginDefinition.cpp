#include "AIPluginDefinition.h"
#include "AIPlugin.h"

//-------------------------------------------------------------------------------
RegisterPluginType("AI", AIPluginDefinition, AIPlugin);

//-------------------------------------------------------------------------------
AIPluginDefinition::AIPluginDefinition()
{
	m_name = "AI";
}

//-------------------------------------------------------------------------------
AIPluginDefinition::~AIPluginDefinition()
{
}

//-------------------------------------------------------------------------------
const TString& AIPluginDefinition::GetControllerName() const
{
	return m_controllerName;
}

//-------------------------------------------------------------------------------
float AIPluginDefinition::GetDecisionDelay() const
{
	return m_decisionDelay;
}

//-------------------------------------------------------------------------------
void AIPluginDefinition::HandleLoadAttributes(TDynamicSet<TDataVariant>& objects)
{
	m_controllerName = TDataVariant::Find("controller", objects).GetString();
	m_decisionDelay = TDataVariant::Find("decisionDelay", objects).GetFloat();
}
