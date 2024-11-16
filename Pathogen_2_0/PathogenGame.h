#ifndef __PATHOGENGAME_H__
#define __PATHOGENGAME_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class PauseStateUpdater;

class PathogenGame
{
public:
	PathogenGame();

	~PathogenGame();

private:
	void CreateGameStates();

	void CreateUIMappings();

	void CreateSingletons();

	void DestroySingletons();

	void RegisterPlugins();

	PauseStateUpdater* m_pauseStateUpdater;

	TDynamicSet<TGameState*> m_gameStates;

	TDynamicSet<TUIController*> m_uiControllers;
};

#endif
