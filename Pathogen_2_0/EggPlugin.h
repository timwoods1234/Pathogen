#ifndef __EGGPLUGIN_H__
#define __EGGPLUGIN_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class Tile;

class EggPlugin : public TPlugin,
				  public TEventListener
{
public:
	static void Register();

	EggPlugin(TEntity* entity, TPluginDefinition* definition);

	~EggPlugin();

	void Update(float elapsedTime);

private:
	void Activate();

	void SpawnAI();

	void MarkTileOccupied(bool occupied);

	void UpdateHatchTimer();

	void UpdateMutiplyTimer();

	void Hatch();

	void Multiply();

	bool CanHatch() const;

	Tile* GetRandomTileNeighbour() const;

	float m_nextMultiplyTime;
	float m_hatchTime;

	bool m_activated;
};

#endif
