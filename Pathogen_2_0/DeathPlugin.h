#ifndef __DEATHPLUGIN_H__
#define __DEATHPLUGIN_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class DeathPlugin : public TPlugin,
				 public TEventListener
{
public:
	static void Register();

	DeathPlugin(TEntity* entity, TPluginDefinition* definition);

	~DeathPlugin();

protected:

	void OnDeath();

	TSound* m_deathSound;
};

#endif
