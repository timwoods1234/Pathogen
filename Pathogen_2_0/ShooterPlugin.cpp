#include "ShooterPlugin.h"
#include "ShooterPluginDefinition.h"
#include "Level.h"
#include "MovementPlugin.h"
#include "Options.h"

//-------------------------------------------------------------------------------
ShooterPlugin::ShooterPlugin(TEntity* entity, TPluginDefinition* definition)
:	TPlugin(entity, definition),
	m_firing(false),
	m_lastFireTime(0.f)
{
	m_projectileDefinition = TEntityDefinition::Acquire("Weapons/DefaultWeapon");

	ShooterPluginDefinition* shooterDefinition = static_cast<ShooterPluginDefinition*>(definition);

	if (shooterDefinition != NULL)
	{
		m_fireSound = TSound::Acquire(shooterDefinition->GetFireSound().GetPointer());
	}

	TEventUpdate::Get()->Register(this, &ShooterPlugin::Update);
}

//-------------------------------------------------------------------------------
ShooterPlugin::~ShooterPlugin()
{
	TEventUpdate::Get()->Unregister(this, &ShooterPlugin::Update);

	TSound::Release(m_fireSound);

	TEntityDefinition::Release(m_projectileDefinition);
}

//-------------------------------------------------------------------------------
void ShooterPlugin::Update(float elapsedTime)
{
	float currentAppTime = TLocator::GetTimer()->GetAppTime();
	float timeSinceFire = currentAppTime - m_lastFireTime;

	ShooterPluginDefinition* definition = static_cast<ShooterPluginDefinition*>(m_definition);

	m_firing = m_firing || Options::Get()->GetAutoFire();

	if (m_firing && timeSinceFire >= definition->GetTimeBetweenAttacks())
	{
		Fire();

		m_lastFireTime = currentAppTime;
	}

	SetFiring(false);
}

//-------------------------------------------------------------------------------
void ShooterPlugin::SetFiring(bool firing)
{
	m_firing = firing;
}

//-------------------------------------------------------------------------------
void ShooterPlugin::Fire()
{
	if (m_projectileDefinition != NULL)
	{
		TEntity* projectile = Level::Get()->CreateEntity(m_projectileDefinition, EntityType::Laser);

		if (projectile != NULL)
		{
			TVector3 position = m_entity->GetPosition();
			TVector3 center = TVector3(TConfig::Get()->GetScreenWidth() * 0.5f, TConfig::Get()->GetScreenHeight() * 0.5f, 0.f);

			projectile->SetPosition(position);

			MovementPlugin* movementPlugin = static_cast<MovementPlugin*>(projectile->GetPlugin("Movement"));
			TASSERT((movementPlugin != NULL), "[ShooterPlugin::Fire] No movement plugin definied for projectile");

			TVector3 directionToOrigin = center - position;
			directionToOrigin.Normalize();

			movementPlugin->SetDirection(TVector2(directionToOrigin.x, directionToOrigin.y));

			if (m_fireSound != NULL)
			{
				m_fireSound->Play();
			}
		}
	}
	else
	{
		TDebugPrint(("[ShooterPlugin::Fire] No weapon definition was found"));
	}
}