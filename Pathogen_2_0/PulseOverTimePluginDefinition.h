#ifndef __PULSEOVERTIMEPLUGINDEFINITION_H__
#define __PULSEOVERTIMEPLUGINDEFINITION_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class PulseOverTimePluginDefinition : public TPluginDefinition
{
public:
	PulseOverTimePluginDefinition();

	~PulseOverTimePluginDefinition();

	float GetPulseSpeed() const;
	
	void HandleLoadAttributes(TDynamicSet<TDataVariant>& objects);

private:
	float m_pulseSpeed;
};

#endif
