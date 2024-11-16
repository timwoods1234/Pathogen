#ifndef __INPUTPLUGINDEFINITION_H__
#define __INPUTPLUGINDEFINITION_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class InputPluginDefinition : public TPluginDefinition
{
public:
	InputPluginDefinition();

	~InputPluginDefinition();

	long GetDeadzone() const;

	void HandleLoadAttributes(TDynamicSet<TDataVariant>& objects);

private:
	long m_deadZone;
};

#endif
