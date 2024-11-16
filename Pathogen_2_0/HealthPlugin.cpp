#include "HealthPlugin.h"
#include "HealthPluginDefinition.h"
#include "Level.h"
#include "ScorePlugin.h"
#include "PlayerStats.h"

//-------------------------------------------------------------------------------
HealthPlugin::HealthPlugin(TEntity* entity, TPluginDefinition* definition)
:	TPlugin(entity, definition),
	m_currentHealth(1.f)
{
	HealthPluginDefinition* healthDefinition = static_cast<HealthPluginDefinition*>(definition);

	if (healthDefinition != NULL)
	{
		SetCurrentHealth(healthDefinition->GetMaxHealth());

		m_vulnerableTime = TLocator::GetTimer()->GetAppTime() + healthDefinition->GetInvulnerableTime();
	}

	m_deathEvent = TNew TEvent();
}

//-------------------------------------------------------------------------------
HealthPlugin::~HealthPlugin()
{
	TSafeDelete(m_deathEvent);
}

//-------------------------------------------------------------------------------
float HealthPlugin::GetCurrentHealth() const
{
	return m_currentHealth;
}

//-------------------------------------------------------------------------------
void HealthPlugin::SetCurrentHealth(float health)
{
	if (m_currentHealth != health && TLocator::GetTimer()->GetAppTime() >= m_vulnerableTime)
	{
		m_currentHealth = health;

		if (m_currentHealth <= 0.f)
		{
			m_currentHealth = 0.f;

			m_deathEvent->Execute();

			AddScore();

			Level::Get()->MarkEntityDead(m_entity);
		}
	}
}

//-------------------------------------------------------------------------------
void HealthPlugin::AddScore()
{
	ScorePlugin* scorePlugin = static_cast<ScorePlugin*>(m_entity->GetPlugin("Score"));

	if (scorePlugin != NULL)
	{
		scorePlugin->AddScore();
	}
}

//-------------------------------------------------------------------------------
TEvent& HealthPlugin::GetDeathEvent() const
{
	return *m_deathEvent;
}