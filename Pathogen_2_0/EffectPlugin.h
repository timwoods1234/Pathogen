#ifndef __EFFECTPLUGIN_H__
#define __EFFECTPLUGIN_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class EffectPlugin : public TPlugin,
					 public TEventListener
{
public:
	static void Register();

	EffectPlugin(TEntity* entity, TPluginDefinition* definition);

	~EffectPlugin();

	void Update(float elapsedTime);
};

#endif
