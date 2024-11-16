#ifndef __AIPLUGIN_H__
#define __AIPLUGIN_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class AIController_Base;

class AIPlugin : public TPlugin,
				 public TEventListener
{
public:
	static void Register();

	AIPlugin(TEntity* entity, TPluginDefinition* definition);

	~AIPlugin();

	void Update(float elapsedTime);

	void OnEnabled();

	void OnDisabled();

private:
	void CreateController(const TString& name);

	float m_nextUpdateTime;

	AIController_Base* m_controller;
};

#endif
