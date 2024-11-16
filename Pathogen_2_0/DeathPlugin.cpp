#include "DeathPlugin.h"
#include "DeathPluginDefinition.h"
#include "HealthPlugin.h"
#include "Level.h"
#include "SpritePlugin.h"

//-------------------------------------------------------------------------------
DeathPlugin::DeathPlugin(TEntity* entity, TPluginDefinition* definition)
:	TPlugin(entity, definition)
,	m_deathSound(NULL)
{
	DeathPluginDefinition* deathPluginDefinition = static_cast<DeathPluginDefinition*>(definition);

	if (deathPluginDefinition != NULL)
	{
		if (deathPluginDefinition->GetDeathSound().GetLength() > 0)
		{
			m_deathSound = TSound::Acquire(deathPluginDefinition->GetDeathSound().GetPointer());
			TASSERT(m_deathSound != NULL, "death plugin has misconfigured sound effect");
		}
	}

	HealthPlugin* healthPlugin = static_cast<HealthPlugin*>(entity->GetPlugin("Health"));

	TASSERT(healthPlugin != NULL, "no Health plugin for Death plugin to listen to");

	if (healthPlugin != NULL)
	{
		healthPlugin->GetDeathEvent().Register(this, &DeathPlugin::OnDeath);
	}
}

//-------------------------------------------------------------------------------
DeathPlugin::~DeathPlugin()
{
	TSound::Release(m_deathSound);
}

//-------------------------------------------------------------------------------
void DeathPlugin::OnDeath()
{
	const DeathPluginDefinition* deathDefinition = static_cast<DeathPluginDefinition*>(m_definition);
	TASSERT(deathDefinition != NULL, "Death Plugin has no definition");

	if (deathDefinition->GetDeathParticle().GetLength() > 0)
	{
		TEntityDefinition* effectDefinition = TEntityDefinition::Acquire(deathDefinition->GetDeathParticle().GetPointer());
		TASSERT(effectDefinition != NULL, "death plugin has misconfigured particle effect");

		TEntity* effectInstance = Level::Get()->CreateEntity(effectDefinition, EntityType::Effect);

		if (effectInstance != NULL)
		{
			TVector3 renderPosition = m_entity->GetPosition();

			SpritePlugin* spritePlugin = static_cast<SpritePlugin*>(m_entity->GetPlugin("Sprite"));

			if (spritePlugin != NULL)
			{
				TAABB spriteBounds;
				spritePlugin->ComputeBounds(spriteBounds);

				TVector3 size;
				spriteBounds.GetSize(size);

				renderPosition -= size * 0.5f;
			}

			effectInstance->SetPosition(renderPosition);
		}

		TEntityDefinition::Release(effectDefinition);
	}

	if (m_deathSound != NULL)
	{
		m_deathSound->Play();
	}
}
