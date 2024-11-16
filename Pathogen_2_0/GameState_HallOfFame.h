#ifndef __GAMESTATE_HALLOFFAME_H__
#define __GAMESTATE_HALLOFFAME_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class GameState_HallOfFame : public TGameState
{
public:
	GameState_HallOfFame();

	~GameState_HallOfFame();

	void OnEntry();

	void OnExit();
};

#endif
