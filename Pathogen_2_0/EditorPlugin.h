#ifndef __EDITORPLUGIN_H__
#define __EDITORPLUGIN_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class EditorPlugin : public TPlugin
{
public:
	static void Register();

	EditorPlugin(TEntity* entity, TPluginDefinition* definition);

	~EditorPlugin();
};

#endif
