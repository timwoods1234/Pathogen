#ifndef __HEALTHPLUGIN_H__
#define __HEALTHPLUGIN_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class HealthPlugin : public TPlugin
{
public:
	static void Register();

	HealthPlugin(TEntity* entity, TPluginDefinition* definition);

	~HealthPlugin();

	float GetCurrentHealth() const;

	void SetCurrentHealth(float health);

	TEvent& GetDeathEvent() const;

private:

	void AddScore();

	float m_currentHealth;

	float m_vulnerableTime;

private:
	TEvent* m_deathEvent;
};

#endif
