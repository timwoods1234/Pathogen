#ifndef __MOVEMENTPLUGINDEFINITION_H__
#define __MOVEMENTPLUGINDEFINITION_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class MovementPluginDefinition : public TPluginDefinition
{
public:
	MovementPluginDefinition();

	float GetSpeed() const;

	void HandleLoadAttributes(TDynamicSet<TDataVariant>& objects);

private:
	float m_speed;
};

#endif
