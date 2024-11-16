#include "PulseOverTimePluginDefinition.h"
#include "PulseOverTimePlugin.h"

//-------------------------------------------------------------------------------
RegisterPluginType("PulseOverTime", PulseOverTimePluginDefinition, PulseOverTimePlugin);

//-------------------------------------------------------------------------------
PulseOverTimePluginDefinition::PulseOverTimePluginDefinition()
: m_pulseSpeed(0.f)
{
	m_name = "PulseOverTime";
}

//-------------------------------------------------------------------------------
PulseOverTimePluginDefinition::~PulseOverTimePluginDefinition()
{
}

//-------------------------------------------------------------------------------
float PulseOverTimePluginDefinition::GetPulseSpeed() const
{
	return m_pulseSpeed;
}

//-------------------------------------------------------------------------------
void PulseOverTimePluginDefinition::HandleLoadAttributes(TDynamicSet<TDataVariant>& objects)
{
	m_pulseSpeed = TDataVariant::Find("pulseSpeed", objects).GetFloat();
}
