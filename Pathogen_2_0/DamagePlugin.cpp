#include "DamagePlugin.h"
#include "ColliderPlugin.h"
#include "DamagePluginDefinition.h"
#include "HealthPlugin.h"
#include "Level.h"

//-------------------------------------------------------------------------------
DamagePlugin::DamagePlugin(TEntity* entity, TPluginDefinition* definition)
:	TPlugin(entity, definition)
{
	ColliderPlugin* collider = static_cast<ColliderPlugin*>(entity->GetPlugin("Collider"));

	if (collider != NULL)
	{
		collider->GetCollisionEvent().Register(this, &DamagePlugin::OnCollision);
	}
}

//-------------------------------------------------------------------------------
DamagePlugin::~DamagePlugin()
{
}

//-------------------------------------------------------------------------------
void DamagePlugin::OnCollision(ColliderPlugin& collidedObject)
{
	TEntity* entity = collidedObject.GetEntity();

	if (entity != NULL)
	{
		DamagePluginDefinition* definition = static_cast<DamagePluginDefinition*>(m_definition);

		unsigned int numTargets = definition->GetNumTargets();
		bool hitTarget = false;

		for (unsigned int index = 0; index < numTargets; index++)
		{
			const TString& target = definition->GetTarget(index);

			TPlugin* plugin = entity->GetPlugin(target);

			if (plugin != NULL)
			{
				hitTarget = true;
				break;
			}
		}

		if (hitTarget)
		{
			float damage = definition->GetDamage();
			HitTarget(entity, damage);

			Level::Get()->MarkEntityDead(m_entity);
		}
	}
}

//-------------------------------------------------------------------------------
void DamagePlugin::HitTarget(TEntity* entity, float damage)
{
	HealthPlugin* healthPlugin = static_cast<HealthPlugin*>(entity->GetPlugin("Health"));

	if (healthPlugin != NULL)
	{
		healthPlugin->SetCurrentHealth(healthPlugin->GetCurrentHealth() - damage);
	}
}
