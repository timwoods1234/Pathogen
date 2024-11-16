#ifndef __PLAYERPOSITIONPLUGINDEFINITION_H__
#define __PLAYERPOSITIONPLUGINDEFINITION_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class PlayerPositionPluginDefinition : public TPluginDefinition
{
public:
	PlayerPositionPluginDefinition();

	~PlayerPositionPluginDefinition();

	float GetSpeed() const;

	float GetCircularDistance() const;

	void HandleLoadAttributes(TDynamicSet<TDataVariant>& objects);

private:
	float m_speed;
	float m_circularDistance;
};

#endif
