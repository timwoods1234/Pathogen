#ifndef __LEVEL_H__
#define __LEVEL_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

#ifndef __ENTITYTYPE_H__
#include "EntityType.h"
#endif

#ifndef __TILE_H__
#include "Tile.h"
#endif

class Level : public TSingleton<Level>,
			  public TEventListener
{
public:
	bool collisionsBeingPerformed; // TODO: remove this
	Level();

	~Level();

	void Reset();

	void RemoveDeadEntities();

	TEntity* CreateEntity(TEntityDefinition* definition, EntityType type);

	void MarkEntityDead(TEntity* entity);

	const TEntity* GetEntity(EntityType type, unsigned int index) const;

	unsigned int GetCount(EntityType type);

	Tile* GetTile(int x, int y);

	TEntity* AddPlayer();

private:
	void SetupTiles();

	void Validate();

	void ValidateList(const TDynamicSet<TEntity*>& entities);

	void ClearEntityList(TDynamicSet<TEntity*>& entities);

	TDynamicSet<TEntity*>& GetEntities(EntityType type);

	void DestroyEntity(TEntity* entity);

	TDynamicArray<Tile> m_tiles;

	// TODO: switch to dynamic array. be consistent with tiles
	TDynamicSet<TEntity*> m_entityLists[(int)EntityType::MAX];

	TDynamicSet<TEntity*> m_deadEntities;
};

#endif
