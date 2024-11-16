#ifndef __EGGPLUGINDEFINITION_H__
#define __EGGPLUGINDEFINITION_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class EggPluginDefinition : public TPluginDefinition
{
public:
	EggPluginDefinition();

	~EggPluginDefinition();

	float GetHatchTime() const;

	float GetMultiplyTime() const;

	unsigned int GetNumSpawnableAIs() const;

	const TString& GetMultiplyPayload() const;

	const TString& GetSpawnableAI(unsigned int index) const;

	void HandleLoadAttributes(TDynamicSet<TDataVariant>& objects);

	TXMLObject* HandleLoadElement(const TString& strID, TDynamicSet<TDataVariant>& objects);

private:
	float m_hatchTime;
	float m_multiplyTime;

	TString m_multiplyPayload;

	TDynamicSet<TString> m_spawnableAIs;
};

#endif
