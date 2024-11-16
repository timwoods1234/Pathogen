#include "EggPlugin.h"
#include "EggPluginDefinition.h"
#include "Level.h"
#include "LevelHelper.h"
#include "GameSettings.h"

//-------------------------------------------------------------------------------
EggPlugin::EggPlugin(TEntity* entity, TPluginDefinition* definition)
:	TPlugin(entity, definition),
	m_activated(false),
	m_hatchTime(0.f),
	m_nextMultiplyTime(0.f)
{
	TEventUpdate::Get()->Register(this, &EggPlugin::Update);
}

//-------------------------------------------------------------------------------
EggPlugin::~EggPlugin()
{
	TEventUpdate::Get()->Unregister(this, &EggPlugin::Update);
}

//-------------------------------------------------------------------------------
void EggPlugin::Update(float elapsedTime)
{
	if (!m_activated)
	{
		Activate();

		m_activated = true;
	}

	if (CanHatch())
	{
		UpdateHatchTimer();
	}

	UpdateMutiplyTimer();
}

//-------------------------------------------------------------------------------
bool EggPlugin::CanHatch() const
{
	if (m_hatchTime > 0.f)
	{
		return true;
	}

	return false;
}

//-------------------------------------------------------------------------------
void EggPlugin::MarkTileOccupied(bool occupied)
{
	TVector2 gridPosition = LevelHelper::World3ToGrid2(m_entity->GetPosition());

	Tile* tile = Level::Get()->GetTile((int)gridPosition.x, (int)gridPosition.y);

	if (tile != NULL)
	{
		// TODO: might need to separate this into the object that creates the entity
		// to avoid 2 being created on the same tile on the same frame
		tile->SetOccupied(occupied);
	}
}

//-------------------------------------------------------------------------------
void EggPlugin::Activate()
{
	MarkTileOccupied(true);

	m_nextMultiplyTime = TLocator::GetTimer()->GetAppTime() + static_cast<EggPluginDefinition*>(m_definition)->GetMultiplyTime();

	m_hatchTime = TLocator::GetTimer()->GetAppTime() + static_cast<EggPluginDefinition*>(m_definition)->GetHatchTime();
}

//-------------------------------------------------------------------------------
void EggPlugin::UpdateHatchTimer()
{
	if (TLocator::GetTimer()->GetAppTime() >= m_hatchTime)
	{
		Hatch();
	}
}

//-------------------------------------------------------------------------------
Tile* EggPlugin::GetRandomTileNeighbour() const
{
	TDynamicSet<Tile*> neighbourTiles;
	TVector2 gridPosition = LevelHelper::World3ToGrid2(m_entity->GetPosition());

	Tile* tileRight = Level::Get()->GetTile((int)gridPosition.x + 1, (int)gridPosition.y);
	Tile* tileLeft = Level::Get()->GetTile((int)gridPosition.x - 1, (int)gridPosition.y);
	Tile* tileUp = Level::Get()->GetTile((int)gridPosition.x, (int)gridPosition.y + 1);
	Tile* tileDown = Level::Get()->GetTile((int)gridPosition.x, (int)gridPosition.y - 1);

	if (tileRight != NULL && !tileRight->IsOccupied())
	{
		neighbourTiles.Add(tileRight);
	}

	if (tileLeft != NULL && !tileLeft->IsOccupied())
	{
		neighbourTiles.Add(tileLeft);
	}

	if (tileUp != NULL && !tileUp->IsOccupied())
	{
		neighbourTiles.Add(tileUp);
	}

	if (tileDown != NULL && !tileDown->IsOccupied())
	{
		neighbourTiles.Add(tileDown);
	}

	if (neighbourTiles.GetSize() > 0)
	{
		unsigned int min = 0;
		unsigned int max = neighbourTiles.GetSize();
		unsigned int seed = (unsigned int)this;
		unsigned int index = FastRandom(&seed, min, max);

		return neighbourTiles[index];
	}
	else
	{
		TDebugPrint(("unable to find neighbour tile"));
	}

	return NULL;
}

//-------------------------------------------------------------------------------
void EggPlugin::Hatch()
{
	SpawnAI();

	MarkTileOccupied(false);

	Level::Get()->MarkEntityDead(m_entity);
}

//-------------------------------------------------------------------------------
void EggPlugin::SpawnAI()
{
	unsigned int numSpawnableAIs = static_cast<EggPluginDefinition*>(m_definition)->GetNumSpawnableAIs();

	if (numSpawnableAIs > 0)
	{
		unsigned int seed = numSpawnableAIs;
		unsigned int zero = 0;
		unsigned int chosenAI = FastRandom(&seed, zero, numSpawnableAIs);

		const TString& chosedDefinitionName = static_cast<EggPluginDefinition*>(m_definition)->GetSpawnableAI(chosenAI);

		TEntityDefinition* chosenDefinition = TEntityDefinition::Acquire(chosedDefinitionName.GetPointer());

		if (chosenDefinition != NULL)
		{
			TEntity* entity = Level::Get()->CreateEntity(chosenDefinition, EntityType::Enemy);

			if (entity != NULL)
			{
				entity->SetPosition(m_entity->GetPosition());
			}
		}

		TEntityDefinition::Release(chosenDefinition);
	}
}

//-------------------------------------------------------------------------------
void EggPlugin::UpdateMutiplyTimer()
{
	if (TLocator::GetTimer()->GetAppTime() >= m_nextMultiplyTime)
	{
		int numEggs = Level::Get()->GetCount(EntityType::Egg);

		if (numEggs < GameSettings::Get()->GetMaxEggs())
		{
			Multiply();
		}

		m_nextMultiplyTime = TLocator::GetTimer()->GetAppTime() + static_cast<EggPluginDefinition*>(m_definition)->GetMultiplyTime();
	}
}

//-------------------------------------------------------------------------------
void EggPlugin::Multiply()
{
	Tile* targetTile = GetRandomTileNeighbour();

	if (targetTile != NULL)
	{
		int x = targetTile->GetX();
		int y = targetTile->GetY();
		int spacing = GameSettings::Get()->GetTileSize();

		TVector3 position((float)(x * spacing), (float)(y * spacing), 0.f);
		TEntity* spawnedEntity = NULL;
		TString spawnDefinitionName = static_cast<EggPluginDefinition*>(m_definition)->GetMultiplyPayload();
		
		if (!spawnDefinitionName.IsEmpty())
		{
			TEntityDefinition* overrideDefinition = TEntityDefinition::Acquire(spawnDefinitionName.GetPointer());

			if (overrideDefinition != NULL)
			{
				spawnedEntity = Level::Get()->CreateEntity(overrideDefinition, EntityType::Egg);
				TEntityDefinition::Release(overrideDefinition);
			}
		}
		else
		{
			TEntityDefinition* spawnDefinition = m_entity->GetDefinition();

			if (spawnDefinition != NULL)
			{
				spawnedEntity = Level::Get()->CreateEntity(spawnDefinition, EntityType::Egg);
			}
		}

		if (spawnedEntity != NULL)
		{
			spawnedEntity->SetPosition(position);
		}
	}
}
