#ifndef __UILEVELEDITOR_H__
#define __UILEVELEDITOR_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class UILevelEditor : public TUIController
{
public:
	UILevelEditor();

	~UILevelEditor();

	void GetDeleteModeState(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void Save(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void Load(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void GetSprite(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void SelectEntityDefinition(const TUIVariableParameter* parameters, TUIVariableResult* result);

	void ToggleDelete(const TUIVariableParameter* parameters, TUIVariableResult* result);
};

#endif
