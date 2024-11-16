#include "LevelEditor.h"
#include "LevelEditorEntryList.h"
#include "LevelEditorDefinitionList.h"
#include "LevelEditorEntry.h"
#include "LevelEditorDisplay.h"
#include "LevelEditorStorage.h"
#include "GameSettings.h"

//-------------------------------------------------------------------------------
DefineSingleton(LevelEditor);

//-------------------------------------------------------------------------------
LevelEditor::LevelEditor()
:	m_deleteMode(false),
	m_placementPosition(0, 0),
	m_selectedDefinition(NULL)
{
	m_definitionList = TNew LevelEditorDefinitionList();
	m_entryList = TNew LevelEditorEntryList();
	m_storage = TNew LevelEditorStorage();
	m_display = TNew LevelEditorDisplay(m_definitionList);

	TEventUpdate::Get()->Register(this, &LevelEditor::Update);
}

//-------------------------------------------------------------------------------
LevelEditor::~LevelEditor()
{
	TEventUpdate::Get()->Unregister(this, &LevelEditor::Update);

	TSafeDelete(m_storage);
	TSafeDelete(m_display);
	TSafeDelete(m_entryList);
	TSafeDelete(m_definitionList);
}

//-------------------------------------------------------------------------------
void LevelEditor::PlaceSelected()
{
	const LevelEditorEntry* existingEntry = m_entryList->GetEntry(m_placementPosition);

	if (existingEntry == NULL && m_selectedDefinition != NULL)
	{
		LevelEditorEntry newEntry(m_selectedDefinition, m_placementPosition);

		m_entryList->AddEntry(newEntry);
	}
}

//-------------------------------------------------------------------------------
void LevelEditor::ToggleDeleteMode()
{
	m_deleteMode = !m_deleteMode;

	m_selectedDefinition = NULL;
}

//-------------------------------------------------------------------------------
bool LevelEditor::IsDeleteEnabled() const
{
	return m_deleteMode;
}

//-------------------------------------------------------------------------------
void LevelEditor::Reset()
{
	m_deleteMode = false;

	m_entryList->ClearAllEntries();

	m_placementPosition.Set(0, 0);

	m_selectedDefinition = NULL;
}

//-------------------------------------------------------------------------------
const TEntityDefinition* LevelEditor::GetSelectedDefinition() const
{
	return m_selectedDefinition;
}

//-------------------------------------------------------------------------------
void LevelEditor::SetSelectedDefinition(unsigned int index)
{
	m_selectedDefinition = m_definitionList->GetEntityDefinition(index);

	m_deleteMode = false;
}

//-------------------------------------------------------------------------------
const TVector2& LevelEditor::GetPlacementPosition() const
{
	return m_placementPosition;
}

//-------------------------------------------------------------------------------
void LevelEditor::Update(float elapsedTime)
{
	UpdateCursorPosition();

	if (TLocator::GetInput()->IsPressed(TINPUT_MOUSE_LEFT))
	{
		if (m_selectedDefinition != NULL)
		{
			PlaceSelected();
		}
		else
		{
			AttemptDelete();
		}
	}
}

//-------------------------------------------------------------------------------
void LevelEditor::AttemptDelete()
{
	const LevelEditorEntry* existingEntry = m_entryList->GetEntry(m_placementPosition);

	if (existingEntry != NULL)
	{
		m_entryList->RemoveEntry(*existingEntry);
	}
}

//-------------------------------------------------------------------------------
void LevelEditor::UpdateCursorPosition()
{
	TLocator::GetInput()->GetMousePosition(m_placementPosition);

	int tileSize = GameSettings::Get()->GetTileSize();

	// todo: remove warning
	m_placementPosition.x = (float)(tileSize * ((int)m_placementPosition.x / tileSize));
	m_placementPosition.y = (float)(tileSize * ((int)m_placementPosition.y / tileSize));
}

//-------------------------------------------------------------------------------
const LevelEditorDefinitionList* LevelEditor::GetDefinitionList() const
{
	return m_definitionList;
}

//-------------------------------------------------------------------------------
LevelEditorEntryList* LevelEditor::GetEntryList() const
{
	return m_entryList;
}

//-------------------------------------------------------------------------------
LevelEditorStorage* LevelEditor::GetStorage() const
{
	return m_storage;
}