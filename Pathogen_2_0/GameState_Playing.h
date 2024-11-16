#ifndef __GAMESTATE_PLAYING_H__
#define __GAMESTATE_PLAYING_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class GameState_Playing : public TGameState,
						  public TEventListener
{
public:
	GameState_Playing();

	~GameState_Playing();

	void OnUpdate(float elapsedTime);

	void OnEntry();

	void OnExit();

private:
	void CheckPlayerState();

	void CheckShieldState();

	void CheckVictoryState();

	TEntity* m_background;
};

#endif
