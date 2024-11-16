#ifndef __ESCAPEPLUGINDEFINITION_H__
#define __ESCAPEPLUGINDEFINITION_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class EscapePluginDefinition : public TPluginDefinition
{
public:
	EscapePluginDefinition();

	~EscapePluginDefinition();

	int GetEscapeDamage() const;

	void HandleLoadAttributes(TDynamicSet<TDataVariant>& objects);

private:
	int m_escapeDamage;
};

#endif
