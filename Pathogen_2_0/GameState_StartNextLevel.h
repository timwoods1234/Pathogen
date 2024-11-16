#ifndef __GAMESTATE_STARTNEWGAME_H__
#define __GAMESTATE_STARTNEWGAME_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class LevelLoader;
class LevelList;

class GameState_StartNextLevel : public TGameState,
								 public TEventListener
{
public:
	GameState_StartNextLevel();

	~GameState_StartNextLevel();

	void OnEntry();

	void OnExit();

	void OnUpdate(float elapsedTime);

private:
	LevelList* m_levelList;
	LevelLoader* m_levelLoader;

	TString m_nextGameState;
};

#endif
