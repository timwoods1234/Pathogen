#include "PulseOverTimePlugin.h"
#include "PulseOverTimePluginDefinition.h"
#include "SpritePlugin.h"

//-------------------------------------------------------------------------------
PulseOverTimePlugin::PulseOverTimePlugin(TEntity* entity, TPluginDefinition* definition)
:	TPlugin(entity, definition)
,	m_timer(0.f)
{
	TEventUpdate::Get()->Register(this, &PulseOverTimePlugin::Update);
	
	float min = 0.f;
	float max = 10.f;
	unsigned int seed = (unsigned int)this;
	m_randomTimeOffset = FastRandom(&seed, min, max);
}

//-------------------------------------------------------------------------------
PulseOverTimePlugin::~PulseOverTimePlugin()
{
	TEventUpdate::Get()->Unregister(this, &PulseOverTimePlugin::Update);
}

//-------------------------------------------------------------------------------
void PulseOverTimePlugin::Update(float elapsedTime)
{
	m_timer += elapsedTime;
	float pulseModifier = static_cast<PulseOverTimePluginDefinition*>(m_definition)->GetPulseSpeed();

	float pulseValue = sinf(pulseModifier * (m_timer + m_randomTimeOffset));

	TVector3 scale = m_entity->GetScale();
	
	scale.x = 0.8f + 0.2f * pulseValue;
	scale.y = 0.8f + 0.2f * pulseValue;
	
	m_entity->SetScale(scale);

	// adjust the render position slightly to make the sprite appear stationary
	SpritePlugin* spritePlugin = static_cast<SpritePlugin*>(m_entity->GetPlugin("Sprite"));

	if (spritePlugin != NULL)
	{
		TAABB spriteBounds;
		spritePlugin->ComputeBounds(spriteBounds);

		TVector3 size;
		spriteBounds.GetSize(size);

		spritePlugin->SetRenderOffset(
			TVector2(
				size.x * -0.1f * pulseValue,
				size.y * -0.1f * pulseValue
			));
	}
}
