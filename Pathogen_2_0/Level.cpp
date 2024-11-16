#include "Level.h"
#include "GameSettings.h"

//-------------------------------------------------------------------------------
DefineSingleton(Level);

//-------------------------------------------------------------------------------
Level::Level()
{
	SetupTiles();
	collisionsBeingPerformed = false;
}

//-------------------------------------------------------------------------------
Level::~Level()
{
	Reset();
}

//-------------------------------------------------------------------------------
TEntity* Level::AddPlayer()
{
	TEntity* result = NULL;
	TEntityDefinition* playerDefinition = TEntityDefinition::Acquire("Player");

	if (playerDefinition != NULL)
	{
		result = CreateEntity(playerDefinition, EntityType::Player);
		TEntityDefinition::Release(playerDefinition);
	}

	Validate();

	return result;
}

//-------------------------------------------------------------------------------
void Level::SetupTiles()
{
	unsigned int gridSize = GameSettings::Get()->GetGridSize();

	m_tiles.Resize(gridSize * gridSize);

	for (unsigned int y = 0; y < gridSize; y++)
	{
		for (unsigned int x = 0; x < gridSize; x++)
		{
			int index = (y * gridSize) + x;

			m_tiles[index].SetIndex(x, y);
		}
	}
}

//-------------------------------------------------------------------------------
void Level::Reset()
{
	Validate();

	m_deadEntities.Clear();

	for (unsigned int typeIndex = 0; typeIndex < (unsigned int)EntityType::MAX; typeIndex++)
	{
		TDynamicSet<TEntity*>& entityList = GetEntities((EntityType)typeIndex);

		ClearEntityList(entityList);
	}

	for (unsigned int index = 0; index < m_tiles.GetSize(); index++)
	{
		m_tiles[index].SetOccupied(false);
	}
}

//-------------------------------------------------------------------------------
void Level::ClearEntityList(TDynamicSet<TEntity*>& entityList)
{
	TASSERT(!collisionsBeingPerformed, "entity removed while collisions are being processed");
	for (unsigned int entityIndex = 0; entityIndex < entityList.GetSize(); entityIndex++)
	{
		TSafeDelete(entityList[entityIndex]);
	}

	entityList.Clear();
}

//-------------------------------------------------------------------------------
void Level::Validate()
{
#if defined(DEBUG) | defined(_DEBUG)
	for (int index = 0; index < (int)EntityType::MAX; index++)
	{
		TDynamicSet<TEntity*>& entityList = GetEntities((EntityType)index);

		ValidateList(entityList);
	}

	ValidateList(m_deadEntities);
#endif
}

//-------------------------------------------------------------------------------
void Level::ValidateList(const TDynamicSet<TEntity*>& entities)
{
	TString currentEntityId = TString::GetEmptyString();

	for (unsigned int index = 0; index < entities.GetSize(); index++)
	{
		if (entities[index] != NULL)
		{
			TEntityDefinition* definition = entities[index]->GetDefinition();

			if (definition != NULL)
			{
				currentEntityId = definition->GetId();

				for (unsigned int index2 = index + 1; index2 < entities.GetSize(); index2++)
				{
					TASSERT((entities[index] != entities[index2]), "[Level::Validate] duplicate Entity detected");
				}
			}
			else
			{
				TASSERT(false, "[Level::Validate] entity has no definition");
			}
		}
	}
}

//-------------------------------------------------------------------------------
void Level::RemoveDeadEntities()
{
	Validate();

	TASSERT(!collisionsBeingPerformed, "entity removed while collisions are being processed");

	for (unsigned int index = 0; index < m_deadEntities.GetSize(); index++)
	{
		DestroyEntity(m_deadEntities[index]);

		m_deadEntities[index] = NULL;
	}

	m_deadEntities.Clear();
}

//-------------------------------------------------------------------------------
TEntity* Level::CreateEntity(TEntityDefinition* definition, EntityType type)
{
	TEntity* result = TNew TEntity(definition);

	TDynamicSet<TEntity*>& entityList = GetEntities(type);

	TASSERT(!entityList.Contains(result), "entity already added");
	entityList.Add(result);
	
	Validate();

	return result;
}

//-------------------------------------------------------------------------------
void Level::DestroyEntity(TEntity* entity)
{
	Validate();

	TASSERT(!collisionsBeingPerformed, "entity removed while collisions are being processed");
	for (int index = 0; index < (int)EntityType::MAX; index++)
	{
		TDynamicSet<TEntity*>& entityList = GetEntities((EntityType)index);
		
		entityList.Remove(entity);
	}

	// TODO: fix crash
	TSafeDelete(entity);
}

//-------------------------------------------------------------------------------
void Level::MarkEntityDead(TEntity* entity)
{
	Validate();

	//TDebugPrint(("Mark As Dead: %s", entity->GetDefinition()->GetId().GetPointer()));

	if (!m_deadEntities.Contains(entity))
	{
		m_deadEntities.Add(entity);
	}

	Validate();
}

//-------------------------------------------------------------------------------
unsigned int Level::GetCount(EntityType type)
{
	TDynamicSet<TEntity*>& entityList = GetEntities(type);

	return entityList.GetSize();
}

//-------------------------------------------------------------------------------
const TEntity* Level::GetEntity(EntityType type, unsigned int index) const
{
	TASSERT((type < EntityType::MAX), "[Level::GetEntity] bad type");
	TASSERT((index < m_entityLists[(unsigned int)type].GetSize()), "[Level::GetEntity] bad index");

	return m_entityLists[(int)type][index];
}

//-------------------------------------------------------------------------------
Tile* Level::GetTile(int x, int y)
{
	if (x < 0 || y < 0)
	{
		return NULL;
	}

	unsigned int index = (y * GameSettings::Get()->GetGridSize()) + x;

	// TODO: remove unsigned warning
	if (index < m_tiles.GetSize())
	{
		return &(m_tiles[index]);
	}

	TASSERT(false, "[Level::GetTile] invalid index");

	return NULL;
}

//-------------------------------------------------------------------------------
TDynamicSet<TEntity*>& Level::GetEntities(EntityType type)
{
	return m_entityLists[(int)type];
}
