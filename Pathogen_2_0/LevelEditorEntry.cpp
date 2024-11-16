#include "LevelEditorEntry.h"

//-------------------------------------------------------------------------------
LevelEditorEntry::LevelEditorEntry()
:	m_definition(NULL),
	m_position(0, 0)
{
}

//-------------------------------------------------------------------------------
LevelEditorEntry::LevelEditorEntry(TEntityDefinition* definition, const TVector2& position)
:	m_position(position),
	m_definition(definition)
{
	m_definition->AddRef();
}

//-------------------------------------------------------------------------------
LevelEditorEntry::~LevelEditorEntry()
{
	TEntityDefinition::Release(m_definition);
}

//-------------------------------------------------------------------------------
TEntityDefinition* LevelEditorEntry::GetDefinition() const
{
	return m_definition;
}

//-------------------------------------------------------------------------------
const TVector2& LevelEditorEntry::GetPosition() const
{
	return m_position;
}
