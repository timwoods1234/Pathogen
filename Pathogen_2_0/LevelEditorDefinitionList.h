#ifndef __LEVELEDITORDEFINITIONLIST_H__
#define __LEVELEDITORDEFINITIONLIST_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class LevelEditorDefinitionList
{
public:
	LevelEditorDefinitionList();

	~LevelEditorDefinitionList();

	TEntityDefinition* GetEntityDefinition(unsigned int index) const;

	unsigned int GetNumEntityDefinitions() const;

private:
	void LoadEntityDefinitions();

	TDynamicSet<TEntityDefinition*> m_definitions;
};

#endif
