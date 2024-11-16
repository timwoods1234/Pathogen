#include "Options.h"

//-------------------------------------------------------------------------------
DefineSingleton(Options);

//-------------------------------------------------------------------------------
Options::Options()
{
	TXMLReader reader("Assets/Save/Options.xml", *this);

	if (reader.WasError())
	{
		Save();
	}
}

//-------------------------------------------------------------------------------
Options::~Options()
{
}

//-------------------------------------------------------------------------------
TXMLObject* Options::HandleLoadElement(const TString& strID, TDynamicSet<TDataVariant>& objects)
{
	return NULL;
}

//-------------------------------------------------------------------------------
void Options::HandleLoadAttributes(TDynamicSet<TDataVariant>& objects)
{
	bool optionsInitialized = TDataVariant::Find("initialized", objects).GetBool();

	if (optionsInitialized)
	{
		float masterVolume = TDataVariant::Find("masterVolume", objects).GetFloat();
		float sfxVolume = TDataVariant::Find("sfxVolume", objects).GetFloat();
		float musicVolume = TDataVariant::Find("musicVolume", objects).GetFloat();
		
		m_autoFire = TDataVariant::Find("autoFire", objects).GetBool();

		TLocator::GetAudio()->SetVolume(masterVolume, TSoundChannel::TSoundChannel_Master);
		TLocator::GetAudio()->SetVolume(sfxVolume, TSoundChannel::TSoundChannel_SFX);
		TLocator::GetAudio()->SetVolume(musicVolume, TSoundChannel::TSoundChannel_Music);
	}
}

//-------------------------------------------------------------------------------
void Options::FinaliseLoad()
{
}

//-------------------------------------------------------------------------------
void Options::Write(TXMLWriter& writer)
{
	writer.WriteAttribute("masterVolume", TLocator::GetAudio()->GetVolume(TSoundChannel::TSoundChannel_Master));
	writer.WriteAttribute("sfxVolume", TLocator::GetAudio()->GetVolume(TSoundChannel::TSoundChannel_SFX));
	writer.WriteAttribute("musicVolume", TLocator::GetAudio()->GetVolume(TSoundChannel::TSoundChannel_Music));
	writer.WriteAttribute("initialized", true);
	writer.WriteAttribute("autoFire", m_autoFire);
}

//-------------------------------------------------------------------------------
void Options::Save()
{
	TXMLWriter writer("Assets/Save/Options.xml", "Options", *this);
}

//-------------------------------------------------------------------------------
bool Options::GetAutoFire() const
{
	return m_autoFire;
}

//-------------------------------------------------------------------------------
void Options::SetAutoFire(bool enable)
{
	m_autoFire = enable;
}
