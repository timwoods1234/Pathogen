#ifndef __GAMESTATE_EDITLEVEL_H__
#define __GAMESTATE_EDITLEVEL_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class GameState_EditLevel : public TGameState
{
public:
	GameState_EditLevel();

	~GameState_EditLevel();

	void OnEntry();

	void OnExit();
};

#endif
