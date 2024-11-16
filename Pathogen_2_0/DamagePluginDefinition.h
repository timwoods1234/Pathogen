#ifndef __DAMAGEPLUGINDEFINITION_H__
#define __DAMAGEPLUGINDEFINITION_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class DamagePluginDefinition : public TPluginDefinition
{
public:
	DamagePluginDefinition();

	~DamagePluginDefinition();

	float GetDamage() const;

	unsigned int GetNumTargets() const;

	const TString& GetTarget(unsigned int index) const;

	TXMLObject* HandleLoadElement(const TString& strID, TDynamicSet<TDataVariant>& objects);

	void HandleLoadAttributes(TDynamicSet<TDataVariant>& objects);

private:
	TDynamicSet<TString> m_allowedTargets;

	float m_damage;
};

#endif
