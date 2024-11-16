#ifndef __PULSEOVERTIMEPLUGIN_H__
#define __PULSEOVERTIMEPLUGIN_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class PulseOverTimePlugin : public TPlugin,
							public TEventListener
{
public:
	static void Register();

	PulseOverTimePlugin(TEntity* entity, TPluginDefinition* definition);

	~PulseOverTimePlugin();

	void Update(float elapsedTime);

private:
	float m_randomTimeOffset;

	// TODO: why does adding this cause a memory issue?
	float m_timer;
};

#endif
