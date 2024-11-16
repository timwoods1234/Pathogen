#ifndef __LEVELEDITORENTRY_H__
#define __LEVELEDITORENTRY_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class LevelEditorEntry
{
public:
	LevelEditorEntry();

	LevelEditorEntry(TEntityDefinition* definition, const TVector2& position);

	~LevelEditorEntry();

	TEntityDefinition* GetDefinition() const;

	const TVector2& GetPosition() const;

private:
	TEntityDefinition* m_definition;
	
	TVector2 m_position;
};

#endif
