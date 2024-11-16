#ifndef __MUSICMANAGER_H__
#define __MUSICMANAGER_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class MusicManager : public TSingleton<MusicManager>
{
public:
	MusicManager();

	~MusicManager();

private:
	void PlayMusic();

	void StopMusic();

	TSound* m_music;
};

#endif
