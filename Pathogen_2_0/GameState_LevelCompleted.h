#ifndef __GAMESTATE_LEVELCOMPLETED_H__
#define __GAMESTATE_LEVELCOMPLETED_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class GameState_LevelCompleted : public TGameState,
								 public TEventListener
{
public:
	GameState_LevelCompleted();

	~GameState_LevelCompleted();

	void OnEntry();

	void OnExit();

	void OnUpdate(float elapsedTime);

private:
	const float c_stateDuration = 3.f;

	float m_entryTime;
};

#endif

