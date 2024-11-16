#include "EffectPlugin.h"
#include "SpritePlugin.h"
#include "Level.h"

//-------------------------------------------------------------------------------
static const TString s_spritePluginId = "Sprite";

//-------------------------------------------------------------------------------
EffectPlugin::EffectPlugin(TEntity* entity, TPluginDefinition* definition)
:	TPlugin(entity, definition)
{
	TEventUpdate::Get()->Register(this, &EffectPlugin::Update);
}

//-------------------------------------------------------------------------------
EffectPlugin::~EffectPlugin()
{
	TEventUpdate::Get()->Unregister(this, &EffectPlugin::Update);
}

//-------------------------------------------------------------------------------
void EffectPlugin::Update(float elapsedTime)
{
	SpritePlugin* spritePlugin = static_cast<SpritePlugin*>(m_entity->GetPlugin(s_spritePluginId));

	if (spritePlugin != NULL && !spritePlugin->IsAnimationPlaying())
	{
		Level::Get()->MarkEntityDead(m_entity);
	}
}
