#include "PlayerPositionPlugin.h"
#include "PlayerPositionPluginDefinition.h"
#include "SpritePlugin.h"

//-------------------------------------------------------------------------------
static const TString s_spritePluginId = "Sprite";

//-------------------------------------------------------------------------------
PlayerPositionPlugin::PlayerPositionPlugin(TEntity* entity, TPluginDefinition* definition)
:	TPlugin(entity, definition),
	m_increaseAngle(false),
	m_decreaseAngle(false)
{
	TEventUpdate::Get()->Register(this, &PlayerPositionPlugin::OnUpdate);

	m_currentAngle = PI * -1.f;
}

//-------------------------------------------------------------------------------
PlayerPositionPlugin::~PlayerPositionPlugin()
{
	TEventUpdate::Get()->Unregister(this, &PlayerPositionPlugin::OnUpdate);
}

//-------------------------------------------------------------------------------
void PlayerPositionPlugin::OnUpdate(float elapsedTime)
{
	float speed = static_cast<PlayerPositionPluginDefinition*>(m_definition)->GetSpeed();
	float distance = static_cast<PlayerPositionPluginDefinition*>(m_definition)->GetCircularDistance();

	if (m_increaseAngle)
	{
		m_currentAngle += speed * elapsedTime;
	}
	else if (m_decreaseAngle)
	{
		m_currentAngle -= speed * elapsedTime;
	}

	float sin, cos;
	SinCos(m_currentAngle, sin, cos);

	TVector3 center = TVector3(TConfig::Get()->GetScreenWidth() * 0.5f, TConfig::Get()->GetScreenHeight() * 0.5f, 0.f);
	TVector3 displacement = TVector3(cos, sin, 0.f);

	displacement.Normalize();
	displacement *= distance;

	m_entity->SetPosition(center + displacement);
	m_entity->SetRotation(TVector3(0.f, 0.f, -m_currentAngle));

	m_increaseAngle = false;
	m_decreaseAngle = false;
}

//-------------------------------------------------------------------------------
void PlayerPositionPlugin::IncreaseAngle()
{
	m_increaseAngle = true;
}

//-------------------------------------------------------------------------------
void PlayerPositionPlugin::DecreaseAngle()
{
	m_decreaseAngle = true;
}
