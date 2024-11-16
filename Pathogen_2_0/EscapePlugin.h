#ifndef __ESCAPEPLUGIN_H__
#define __ESCAPEPLUGIN_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class EscapePlugin : public TPlugin,
					 public TEventListener
{
public:
	static void Register();

	EscapePlugin(TEntity* entity, TPluginDefinition* definition);

	~EscapePlugin();

	void OnUpdate(float elapsedTime);

private:
	void OnEscaped();

	bool m_hasEscaped;
};

#endif

