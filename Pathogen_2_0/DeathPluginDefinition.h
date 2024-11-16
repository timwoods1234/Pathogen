#ifndef __DEATHPLUGINDEFINITION_H__
#define __DEATHPLUGINDEFINITION_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class DeathPluginDefinition : public TPluginDefinition
{
public:
	DeathPluginDefinition();

	~DeathPluginDefinition();

	const TString& GetDeathParticle() const;

	const TString& GetDeathSound() const;

	void HandleLoadAttributes(TDynamicSet<TDataVariant>& objects);

private:
	TString m_deathParticle;
	TString m_deathSound;
};

#endif
