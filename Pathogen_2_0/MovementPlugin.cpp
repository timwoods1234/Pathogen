#include "MovementPlugin.h"
#include "MovementPluginDefinition.h"

//-------------------------------------------------------------------------------
MovementPlugin::MovementPlugin(TEntity* entity, TPluginDefinition* definition)
:	TPlugin(entity, definition),
	m_direction(0, 0)
{
	TEventUpdate::Get()->Register(this, &MovementPlugin::Update);
}

//-------------------------------------------------------------------------------
MovementPlugin::~MovementPlugin()
{
	TEventUpdate::Get()->Unregister(this, &MovementPlugin::Update);
}

//-------------------------------------------------------------------------------
void MovementPlugin::Update(float elapsedTime)
{
	TVector3 position = m_entity->GetPosition();

	float speed = static_cast<MovementPluginDefinition*>(m_definition)->GetSpeed();

	position.x += m_direction.x * elapsedTime * speed;
	position.y += m_direction.y * elapsedTime * speed;

	m_entity->SetPosition(position);
}

//-------------------------------------------------------------------------------
void MovementPlugin::SetDirection(const TVector2& direction)
{
	m_direction = direction;

	TASSERT(m_direction.IsNormalized(), "[MovementPlugin::SetDirection] direction is not normal, this could have unwanted behaviour");
}
