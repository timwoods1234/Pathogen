#include "EffectPluginDefinition.h"
#include "EffectPlugin.h"

//-------------------------------------------------------------------------------
RegisterPluginType("EffectPlugin", EffectPluginDefinition, EffectPlugin);

//-------------------------------------------------------------------------------
EffectPluginDefinition::EffectPluginDefinition()
{
	m_name = "EffectPlugin";
}

//-------------------------------------------------------------------------------
EffectPluginDefinition::~EffectPluginDefinition()
{
}
