#ifndef __GAMESTATE_ENTERHALLOFFAME_H__
#define __GAMESTATE_ENTERHALLOFFAME_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class GameState_EnterHallOfFame : public TGameState,
								  public TEventListener
{
public:
	GameState_EnterHallOfFame();

	~GameState_EnterHallOfFame();

	void OnEntry();

	void OnExit();
};

#endif
