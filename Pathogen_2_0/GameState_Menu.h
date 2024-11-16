#ifndef __GAMESTATE_MENU_H__
#define __GAMESTATE_MENU_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class GameState_Menu : public TGameState
{
public:
	GameState_Menu();

	~GameState_Menu();

	void OnEntry();

	void OnExit();
};

#endif
