#ifndef __AIPLUGINDEFINITION_H__
#define __AIPLUGINDEFINITION_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class AIPluginDefinition : public TPluginDefinition
{
public:
	AIPluginDefinition();

	~AIPluginDefinition();

	const TString& GetControllerName() const;

	float GetDecisionDelay() const;

	void HandleLoadAttributes(TDynamicSet<TDataVariant>& objects);

private:
	TString m_controllerName;

	float m_decisionDelay;
};

#endif
