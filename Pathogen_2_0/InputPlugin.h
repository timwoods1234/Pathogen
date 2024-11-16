#ifndef __INPUTPLUGIN_H__
#define __INPUTPLUGIN_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class InputController_Base;

class InputPlugin : public TPlugin,
					public TEventListener
{
public:
	static void Register();

	InputPlugin(TEntity* entity, TPluginDefinition* definition);

	~InputPlugin();

	void Update(float elapsedTime);

private:
	// TODO: maybe have an active plugin to avoid conflicts, or make this a setting
	TDynamicSet<InputController_Base*> m_inputControllers;
};

#endif
