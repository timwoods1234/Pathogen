#include "EscapePlugin.h"
#include "EscapePluginDefinition.h"
#include "GameSettings.h"
#include "Level.h"
#include "PlayerStats.h"

//-------------------------------------------------------------------------------
EscapePlugin::EscapePlugin(TEntity* entity, TPluginDefinition* definition)
:	TPlugin(entity, definition),
	m_hasEscaped(false)
{
	TEventUpdate::Get()->Register(this, &EscapePlugin::OnUpdate);
}

//-------------------------------------------------------------------------------
EscapePlugin::~EscapePlugin()
{
	TEventUpdate::Get()->Unregister(this, &EscapePlugin::OnUpdate);
}

//-------------------------------------------------------------------------------
void EscapePlugin::OnUpdate(float elapsedTime)
{
	TVector3 center = TVector3(TConfig::Get()->GetScreenWidth() * 0.5f, TConfig::Get()->GetScreenHeight() * 0.5f, 0.f);
	float distanceTravelled = (m_entity->GetPosition() - center).GetLength();

	if (!m_hasEscaped && distanceTravelled >= GameSettings::Get()->GetEnemyEscapeDistance())
	{
		OnEscaped();

		m_hasEscaped = true;
	}
	else if (distanceTravelled >= GameSettings::Get()->GetEnemyDestroyDistance())
	{
		Level::Get()->MarkEntityDead(m_entity);
	}
}

//-------------------------------------------------------------------------------
void EscapePlugin::OnEscaped()
{
	EscapePluginDefinition* escapeDefinition = static_cast<EscapePluginDefinition*>(m_definition);

	if (escapeDefinition != NULL)
	{
		int newShield = PlayerStats::Get()->GetCurrentShield() - escapeDefinition->GetEscapeDamage();

		PlayerStats::Get()->SetCurrentShield(newShield);
	}
}
