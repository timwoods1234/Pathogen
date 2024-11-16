#ifndef __SHOOTERPLUGINDEFINITION_H__
#define __SHOOTERPLUGINDEFINITION_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class ShooterPluginDefinition : public TPluginDefinition
{
public:
	ShooterPluginDefinition();

	float GetTimeBetweenAttacks() const;

	const TString& GetFireSound() const;

	void HandleLoadAttributes(TDynamicSet<TDataVariant>& objects);

private:
	float m_timeBetweenAttacks;

	TString m_fireSound;
};

#endif
