#ifndef __LEVELEDITORDISPLAY_H__
#define __LEVELEDITORDISPLAY_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class LevelEditor;
class LevelEditorDefinitionList;

class LevelEditorDisplay : public TEventListener
{
public:
	LevelEditorDisplay(const LevelEditorDefinitionList* definitionList);

	~LevelEditorDisplay();

	void Render();

private:
	void LoadSprites(const LevelEditorDefinitionList* definitionList);

	TSprite* GetSprite(const TString& filename) const;

	TDynamicSet<TSprite*> m_sprites;

	TSprite* m_placementSprite;

	TSprite* m_deleteSprite;
};

#endif

