#include "MusicManager.h"

//-------------------------------------------------------------------------------
DefineSingleton(MusicManager);

//-------------------------------------------------------------------------------
MusicManager::MusicManager()
:	m_music(NULL)
{
	m_music = TSound::Acquire("music");

	PlayMusic();
}

//-------------------------------------------------------------------------------
MusicManager::~MusicManager()
{
	StopMusic();

	TSound::Release(m_music);
}

//-------------------------------------------------------------------------------
void MusicManager::PlayMusic()
{
	m_music->Play();
}

//-------------------------------------------------------------------------------
void MusicManager::StopMusic()
{
	m_music->Stop();
}
