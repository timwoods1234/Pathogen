#ifndef __GAMESTATE_OPTIONS_H__
#define __GAMESTATE_OPTIONS_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class GameState_Options : public TGameState
{
public:
	GameState_Options();

	~GameState_Options();

	void OnEntry();

	void OnExit();
};

#endif
