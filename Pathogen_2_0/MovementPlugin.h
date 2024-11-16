#ifndef __MOVEMENTPLUGIN_H__
#define __MOVEMENTPLUGIN_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class MovementPlugin :  public TPlugin,
						public TEventListener
{
public:
	static void Register();

	MovementPlugin(TEntity* entity, TPluginDefinition* definition);

	~MovementPlugin();

	void Update(float elapsedTime);

	void SetDirection(const TVector2& direction);

private:
	TVector2 m_direction;
};

#endif
