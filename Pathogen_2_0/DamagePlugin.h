#ifndef __DAMAGEPLUGIN_H__
#define __DAMAGEPLUGIN_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class ColliderPlugin;

class DamagePlugin : public TPlugin,
					 public TEventListener
{
public:
	static void Register();

	DamagePlugin(TEntity* entity, TPluginDefinition* definition);

	~DamagePlugin();

	void OnCollision(ColliderPlugin& collidedObject);

private:
	void HitTarget(TEntity* entity, float damage);
};

#endif
