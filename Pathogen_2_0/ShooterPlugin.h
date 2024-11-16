#ifndef __SHOOTERPLUGIN_H__
#define __SHOOTERPLUGIN_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class ShooterPlugin : public TPlugin,
					  public TEventListener
{
public:
	static void Register();

	ShooterPlugin(TEntity* entity, TPluginDefinition* definition);

	~ShooterPlugin();

	void Update(float elapsedTime);

	void SetFiring(bool firing);

private:
	void Fire();

	TEntityDefinition* m_projectileDefinition;

	TSound* m_fireSound;

	bool m_firing;

	float m_lastFireTime;
};

#endif
