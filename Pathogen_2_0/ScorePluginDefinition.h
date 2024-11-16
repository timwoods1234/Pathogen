#ifndef __SCOREPLUGINDEFINITION_H__
#define __SCOREPLUGINDEFINITION_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class ScorePluginDefinition : public TPluginDefinition
{
public:
	ScorePluginDefinition();

	int GetScore() const;

	void HandleLoadAttributes(TDynamicSet<TDataVariant>& objects);

private:
	int m_score;
};

#endif
