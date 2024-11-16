#ifndef __LEVELEDITOR_H__
#define __LEVELEDITOR_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class LevelEditorDefinitionList;
class LevelEditorEntryList;
class LevelEditorEntry;
class LevelEditorDisplay;
class LevelEditorStorage;

class LevelEditor : public TEventListener,
					public TSingleton<LevelEditor>
{
public:
	LevelEditor();

	~LevelEditor();

	void SetSelectedDefinition(unsigned int index);

	const TEntityDefinition* GetSelectedDefinition() const;

	const TVector2& GetPlacementPosition() const;

	void ToggleDeleteMode();

	bool IsDeleteEnabled() const;

	// TODO: are you sure? (done at UI level)
	void Reset();

	void Update(float elapsedTime);

	const LevelEditorDefinitionList* GetDefinitionList() const;

	LevelEditorEntryList* GetEntryList() const;

	LevelEditorStorage* GetStorage() const;

private:
	void UpdateCursorPosition();

	void PlaceSelected();

	void AttemptDelete();

	LevelEditorDisplay* m_display;
	LevelEditorDefinitionList* m_definitionList;
	LevelEditorEntryList* m_entryList;
	LevelEditorStorage* m_storage;

	TEntityDefinition* m_selectedDefinition;
	TVector2 m_placementPosition;

	bool m_deleteMode;
};

#endif
