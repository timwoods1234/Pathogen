#include "ScorePluginDefinition.h"
#include "ScorePlugin.h"

//-------------------------------------------------------------------------------
RegisterPluginType("Score", ScorePluginDefinition, ScorePlugin);

//-------------------------------------------------------------------------------
ScorePluginDefinition::ScorePluginDefinition()
:	m_score(0)
{
	m_name = "Score";
}

//-------------------------------------------------------------------------------
int ScorePluginDefinition::GetScore() const
{
	return m_score;
}

//-------------------------------------------------------------------------------
void ScorePluginDefinition::HandleLoadAttributes(TDynamicSet<TDataVariant>& objects)
{
	m_score = TDataVariant::Find("score", objects).GetInt();
}
