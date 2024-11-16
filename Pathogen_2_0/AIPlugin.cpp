#include "ColliderPlugin.h"
#include "AIPlugin.h"
#include "AIPluginDefinition.h"
#include "Level.h"
#include "HealthPlugin.h"

#include "AIController_Base.h"
#include "AIController_GoForward.h"
#include "AIController_Homing.h"
#include "AIController_RandomDirections.h"

//-------------------------------------------------------------------------------
AIPlugin::AIPlugin(TEntity* entity, TPluginDefinition* definition)
:	TPlugin(entity, definition),
	m_controller(NULL)
{
}

//-------------------------------------------------------------------------------
AIPlugin::~AIPlugin()
{
	OnDisabled();
}

//-------------------------------------------------------------------------------
void AIPlugin::Update(float elapsedTime)
{
	if (m_controller != NULL)
	{
		float currentTime = TLocator::GetTimer()->GetAppTime();

		if (currentTime >= m_nextUpdateTime)
		{
			m_controller->Update(elapsedTime);

			m_nextUpdateTime = TLocator::GetTimer()->GetAppTime() + static_cast<AIPluginDefinition*>(m_definition)->GetDecisionDelay();
		}
	}
}

//-------------------------------------------------------------------------------
void AIPlugin::CreateController(const TString& name)
{
	if (name == "AIHoming")
	{
		m_controller = TNew AIController_Homing(this);
	}
	else if (name == "AIRandomDirections")
	{
		m_controller = TNew AIController_RandomDirections(this);
	}
	else if (name == "AIForward")
	{
		m_controller = TNew AIController_GoForward(this);
	}
	else
	{
		TASSERT(false, "[AIPlugin::CreateController] Unrecognized controller type");
	}
}

//-------------------------------------------------------------------------------
void AIPlugin::OnEnabled()
{
	AIPluginDefinition* aiDefinition = static_cast<AIPluginDefinition*>(m_definition);

	if (aiDefinition != NULL)
	{
		CreateController(aiDefinition->GetControllerName());

		TEventUpdate::Get()->Register(this, &AIPlugin::Update);

		m_nextUpdateTime = TLocator::GetTimer()->GetAppTime() + static_cast<AIPluginDefinition*>(aiDefinition)->GetDecisionDelay();
	}
}

//-------------------------------------------------------------------------------
void AIPlugin::OnDisabled()
{
	TEventUpdate::Get()->Unregister(this, &AIPlugin::Update);

	TSafeDelete(m_controller);
}
