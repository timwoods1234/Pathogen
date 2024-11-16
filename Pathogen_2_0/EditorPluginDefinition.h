#ifndef __EDITORPLUGINDEFINITION_H__
#define __EDITORPLUGINDEFINITION_H__

// stores all editor-related data for an entity
// TODO: get dynamic grids to work so that this can expose the UI sprite properly

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class EditorPluginDefinition : public TPluginDefinition
{
public:
	EditorPluginDefinition();

	~EditorPluginDefinition();

	const TString& GetEditorSprite() const;

	void HandleLoadAttributes(TDynamicSet<TDataVariant>& objects);

private:
	TString m_editorSprite;
};

#endif
