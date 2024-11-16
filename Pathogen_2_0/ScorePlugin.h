#ifndef __SCOREPLUGIN_H__
#define __SCOREPLUGIN_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class ScorePlugin : public TPlugin
{
public:
	static void Register();

	ScorePlugin(TEntity* entity, TPluginDefinition* definition);

	void AddScore();
};

#endif
