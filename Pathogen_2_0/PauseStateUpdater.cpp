#include "PauseStateUpdater.h"

PauseStateUpdater::PauseStateUpdater()
{
	TEventUIUpdate::Get()->Register(this, &PauseStateUpdater::OnUpdate);
}

PauseStateUpdater::~PauseStateUpdater()
{
	TEventUIUpdate::Get()->Unregister(this, &PauseStateUpdater::OnUpdate);
}

void PauseStateUpdater::OnUpdate()
{
	bool pause = true;
	const TGameState* CurrentGameState = TGameState::GetCurrentGameState();

	if (CurrentGameState != NULL)
	{
		if (CurrentGameState->GetStateName() == "Playing" ||
			CurrentGameState->GetStateName() == "StartNextLevel" ||
			CurrentGameState->GetStateName() == "LevelCompleted")
		{
			pause = false;
		}
	}

	TLocator::GetTimer()->SetPause(pause);
}