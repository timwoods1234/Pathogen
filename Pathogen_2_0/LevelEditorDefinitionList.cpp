#include "LevelEditorDefinitionList.h"

//-------------------------------------------------------------------------------
LevelEditorDefinitionList::LevelEditorDefinitionList()
{
	LoadEntityDefinitions();
}

//-------------------------------------------------------------------------------
LevelEditorDefinitionList::~LevelEditorDefinitionList()
{
	TEntityDefinition::ReleaseFolder(m_definitions);
}

//-------------------------------------------------------------------------------
void LevelEditorDefinitionList::LoadEntityDefinitions()
{
	TEntityDefinition::AcquireFolder("Enemy", m_definitions);
}

//-------------------------------------------------------------------------------
TEntityDefinition* LevelEditorDefinitionList::GetEntityDefinition(unsigned int index) const
{
	TEntityDefinition* result = NULL;

	if (index < m_definitions.GetSize())
	{
		result = m_definitions[index];
	}

	return result;
}

//-------------------------------------------------------------------------------
unsigned int LevelEditorDefinitionList::GetNumEntityDefinitions() const
{
	return m_definitions.GetSize();
}
