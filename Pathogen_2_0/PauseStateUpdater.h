#ifndef __PAUSESTATEUPDATER_H__
#define __PAUSESTATEUPDATER_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class PauseStateUpdater : public TEventListener
{
public:
	PauseStateUpdater();

	~PauseStateUpdater();

	void OnUpdate();
};

#endif
