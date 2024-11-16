#include "EditorPluginDefinition.h"
#include "EditorPlugin.h"

//-------------------------------------------------------------------------------
RegisterPluginType("EditorPlugin", EditorPluginDefinition, EditorPlugin);

//-------------------------------------------------------------------------------
EditorPluginDefinition::EditorPluginDefinition()
{
	m_name = "EditorPlugin";

	m_editorSprite = TString::GetEmptyString();
}

//-------------------------------------------------------------------------------
EditorPluginDefinition::~EditorPluginDefinition()
{
}

//-------------------------------------------------------------------------------
const TString& EditorPluginDefinition::GetEditorSprite() const
{
	return m_editorSprite;
}

//-------------------------------------------------------------------------------
void EditorPluginDefinition::HandleLoadAttributes(TDynamicSet<TDataVariant>& objects)
{
	m_editorSprite = TDataVariant::Find("editorSprite", objects).GetString();
}
