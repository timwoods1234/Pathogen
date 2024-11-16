#ifndef __PLAYERPOSITIONPLUGIN_H__
#define __PLAYERPOSITIONPLUGIN_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class PlayerPositionPlugin : public TPlugin,
							 public TEventListener
{
public:
	static void Register();

	PlayerPositionPlugin(TEntity* entity, TPluginDefinition* definition);

	~PlayerPositionPlugin();

	// TODO: make consistent use of Update vs OnUpdate
	void OnUpdate(float elapsedTime);

	void IncreaseAngle();

	void DecreaseAngle();

private:
	float m_currentAngle;

	bool m_increaseAngle;
	bool m_decreaseAngle;
};

#endif
