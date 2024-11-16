#ifndef __HEALTHPLUGINDEFINITION_H__
#define __HEALTHPLUGINDEFINITION_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class HealthPluginDefinition : public TPluginDefinition
{
public:
	HealthPluginDefinition();

	~HealthPluginDefinition();

	float GetMaxHealth() const;

	float GetInvulnerableTime() const;

	void HandleLoadAttributes(TDynamicSet<TDataVariant>& objects);

private:
	float m_maxHealth;
	float m_invulnerableTime;
};

#endif
