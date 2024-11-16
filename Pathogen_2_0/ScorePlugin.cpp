#include "ScorePlugin.h"
#include "ScorePluginDefinition.h"
#include "PlayerStats.h"

//-------------------------------------------------------------------------------
ScorePlugin::ScorePlugin(TEntity* entity, TPluginDefinition* definition)
:	TPlugin(entity, definition)
{
}

//-------------------------------------------------------------------------------
void ScorePlugin::AddScore()
{
	ScorePluginDefinition* scoreDefinition = static_cast<ScorePluginDefinition*>(m_definition);

	int score = scoreDefinition->GetScore();

	int newScore = PlayerStats::Get()->GetCurrentScore() + score;

	PlayerStats::Get()->SetCurrentScore(newScore);
}
