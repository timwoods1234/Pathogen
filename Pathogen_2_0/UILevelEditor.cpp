#include "UILevelEditor.h"
#include "LevelEditor.h"
#include "LevelEditorDefinitionList.h"
#include "LevelEditorStorage.h"
#include "EditorPluginDefinition.h"

//-------------------------------------------------------------------------------
UILevelEditor::UILevelEditor()
{
	TUIMappingContainer::Get()->Register("LevelEditor", "GetSprite", this, &UILevelEditor::GetSprite);
	TUIMappingContainer::Get()->Register("LevelEditor", "SelectEntityDefinition", this, &UILevelEditor::SelectEntityDefinition);
	TUIMappingContainer::Get()->Register("LevelEditor", "ToggleDelete", this, &UILevelEditor::ToggleDelete);
	TUIMappingContainer::Get()->Register("LevelEditor", "DeleteModeState", this, &UILevelEditor::GetDeleteModeState);
	TUIMappingContainer::Get()->Register("LevelEditor", "Save", this, &UILevelEditor::Save);
	TUIMappingContainer::Get()->Register("LevelEditor", "Load", this, &UILevelEditor::Load);
}

//-------------------------------------------------------------------------------
UILevelEditor::~UILevelEditor()
{
	TUIMappingContainer::Get()->UnregisterMappings("LevelEditor");
}

//-------------------------------------------------------------------------------
void UILevelEditor::GetSprite(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	int index = parameters->intValue;

	const TEntityDefinition* definition = LevelEditor::Get()->GetDefinitionList()->GetEntityDefinition(index);

	if (definition != NULL)
	{
		const EditorPluginDefinition* editorDefinition = static_cast<EditorPluginDefinition*>(definition->GetPluginDefinition("EditorPlugin"));

		if (editorDefinition != NULL)
		{
			result->stringValue = editorDefinition->GetEditorSprite();
		}
	}
}

//-------------------------------------------------------------------------------
void UILevelEditor::SelectEntityDefinition(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	LevelEditor::Get()->SetSelectedDefinition(parameters->intValue);
}

//-------------------------------------------------------------------------------
void UILevelEditor::ToggleDelete(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	LevelEditor::Get()->ToggleDeleteMode();
}

//-------------------------------------------------------------------------------
void UILevelEditor::Save(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	LevelEditor::Get()->GetStorage()->OpenSaveDialog();
}

//-------------------------------------------------------------------------------
void UILevelEditor::Load(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	LevelEditor::Get()->GetStorage()->OpenLoadDialog();
}

//-------------------------------------------------------------------------------
void UILevelEditor::GetDeleteModeState(const TUIVariableParameter* parameters, TUIVariableResult* result)
{
	if (LevelEditor::Get()->IsDeleteEnabled())
	{
		result->stringValue = "Enabled";
	}
	else
	{
		result->stringValue = "Disabled";
	}
}
