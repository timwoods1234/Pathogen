#include "LevelEditorDisplay.h"
#include "LevelEditor.h"
#include "LevelEditorEntryList.h"
#include "SpritePluginDefinition.h"
#include "LevelEditorDefinitionList.h"
#include "LevelEditorEntry.h"

//-------------------------------------------------------------------------------
LevelEditorDisplay::LevelEditorDisplay(const LevelEditorDefinitionList* definitionList)
:	m_placementSprite(NULL)
{
	LoadSprites(definitionList);

	TEventRender::Get()->Register(this, &LevelEditorDisplay::Render);
}

//-------------------------------------------------------------------------------
LevelEditorDisplay::~LevelEditorDisplay()
{
	TEventRender::Get()->Unregister(this, &LevelEditorDisplay::Render);

	TSprite::Unload(m_deleteSprite);

	for (unsigned int index = 0; index < m_sprites.GetSize(); index++)
	{
		TSprite::Unload(m_sprites[index]);
	}
}

//-------------------------------------------------------------------------------
void LevelEditorDisplay::LoadSprites(const LevelEditorDefinitionList* definitionList)
{
	m_deleteSprite = TSprite::Load("EditorDelete");

	const TEntityDefinition* currentDefinition = NULL;
	const SpritePluginDefinition* spritePluginDefinition = NULL;

	for (unsigned int index = 0; index < definitionList->GetNumEntityDefinitions(); index++)
	{
		currentDefinition = definitionList->GetEntityDefinition(index);

		if (currentDefinition != NULL)
		{
			spritePluginDefinition = static_cast<SpritePluginDefinition*>(currentDefinition->GetPluginDefinition("Sprite"));

			if (spritePluginDefinition != NULL)
			{
				TString spriteFilename = spritePluginDefinition->GetFilename();
				TSprite* newSprite = TSprite::Load(spriteFilename.GetPointer());

				if (newSprite != NULL)
				{
					m_sprites.Add(newSprite);
				}
			}
		}
	}
}

//-------------------------------------------------------------------------------
TSprite* LevelEditorDisplay::GetSprite(const TString& filename) const
{
	TSprite* result = NULL;
	unsigned int numSprites = m_sprites.GetSize();

	for (unsigned int index = 0; index < numSprites; index++)
	{
		if (m_sprites[index]->GetDefinition()->GetId() == filename)
		{
			result = m_sprites[index];
			break;
		}
	}

	return result;
}

//-------------------------------------------------------------------------------
void LevelEditorDisplay::Render()
{
	const LevelEditorEntryList* entryList = LevelEditor::Get()->GetEntryList();
	unsigned int numEntries = entryList->GetNumEntries();
	TSprite* currentSprite;
	const LevelEditorEntry* currentEntry;
	SpritePluginDefinition* spritePluginDefinition = NULL;

	if (numEntries > 0)
	{
		for (unsigned int index = 0; index < numEntries; index++)
		{
			currentEntry = entryList->GetEntry(index);

			if (currentEntry != NULL)
			{
				spritePluginDefinition = static_cast<SpritePluginDefinition*>(currentEntry->GetDefinition()->GetPluginDefinition("Sprite"));

				if (spritePluginDefinition != NULL)
				{
					currentSprite = GetSprite(spritePluginDefinition->GetFilename());

					if (currentSprite != NULL)
					{
						currentSprite->RenderAt(currentEntry->GetPosition());
					}
				}
			}
		}
	}

	if (LevelEditor::Get()->IsDeleteEnabled())
	{
		m_deleteSprite->RenderAt(LevelEditor::Get()->GetPlacementPosition());
	}

	const TEntityDefinition* selectedDefinition = LevelEditor::Get()->GetSelectedDefinition();

	if (selectedDefinition != NULL)
	{
		spritePluginDefinition = static_cast<SpritePluginDefinition*>(selectedDefinition->GetPluginDefinition("Sprite"));

		if (spritePluginDefinition != NULL)
		{
			currentSprite = GetSprite(spritePluginDefinition->GetFilename());

			if (currentSprite != NULL)
			{
				currentSprite->RenderAt(LevelEditor::Get()->GetPlacementPosition());
			}
		}
	}
}
