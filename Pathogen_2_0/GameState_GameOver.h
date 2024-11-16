#ifndef __GAMESTATE_GAMEOVER_H__
#define __GAMESTATE_GAMEOVER_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class GameState_GameOver : public TGameState
{
public:
	GameState_GameOver();

	~GameState_GameOver();

	void OnEntry();

	void OnExit();
};

#endif
