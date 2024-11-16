#include "EggPluginDefinition.h"
#include "EggPlugin.h"

//-------------------------------------------------------------------------------
RegisterPluginType("Egg", EggPluginDefinition, EggPlugin);

//-------------------------------------------------------------------------------
EggPluginDefinition::EggPluginDefinition()
: m_hatchTime(0.f)
{
	m_name = "Egg";
}

//-------------------------------------------------------------------------------
EggPluginDefinition::~EggPluginDefinition()
{
}

//-------------------------------------------------------------------------------
float EggPluginDefinition::GetHatchTime() const
{
	return m_hatchTime;
}

//-------------------------------------------------------------------------------
float EggPluginDefinition::GetMultiplyTime() const
{
	return m_multiplyTime;
}

//-------------------------------------------------------------------------------
unsigned int EggPluginDefinition::GetNumSpawnableAIs() const
{
	return m_spawnableAIs.GetSize();
}

//-------------------------------------------------------------------------------
const TString& EggPluginDefinition::GetSpawnableAI(unsigned int index) const
{
	return m_spawnableAIs[index];
}

//-------------------------------------------------------------------------------
void EggPluginDefinition::HandleLoadAttributes(TDynamicSet<TDataVariant>& objects)
{
	m_hatchTime = TDataVariant::Find("hatchTime", objects).GetFloat();
	m_multiplyTime = TDataVariant::Find("multiplyTime", objects).GetFloat();
	m_multiplyPayload = TDataVariant::Find("multiplyPayload", objects).GetString();
}

//-------------------------------------------------------------------------------
TXMLObject* EggPluginDefinition::HandleLoadElement(const TString& strID, TDynamicSet<TDataVariant>& objects)
{
	if (strID == "SpawnableAI")
	{
		TString aiName = TDataVariant::Find("id", objects).GetString();
		m_spawnableAIs.Add(aiName);
	}

	return NULL;
}

//-------------------------------------------------------------------------------
const TString& EggPluginDefinition::GetMultiplyPayload() const
{
	return m_multiplyPayload;
}
