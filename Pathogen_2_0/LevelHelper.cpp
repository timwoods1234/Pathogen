#include "LevelHelper.h"
#include "GameSettings.h"

//-------------------------------------------------------------------------------
TVector2 LevelHelper::World3ToGrid2(const TVector3& worldPosition)
{
	unsigned int tileSize = GameSettings::Get()->GetTileSize();

	TVector2 result(worldPosition.x / tileSize, worldPosition.y / tileSize);

	return result;
}

//-------------------------------------------------------------------------------
TVector3 LevelHelper::Grid2ToWorld3(const TVector2& gridPosition)
{
	unsigned int tileSize = GameSettings::Get()->GetTileSize();

	TVector3 result(gridPosition.x * tileSize, gridPosition.y * tileSize, 0.f);

	return result;
}

//-------------------------------------------------------------------------------
TVector2 LevelHelper::Grid2ToWorld2(const TVector2& gridPosition)
{
	unsigned int tileSize = GameSettings::Get()->GetTileSize();

	TVector2 result(gridPosition.x * tileSize, gridPosition.y * tileSize);

	return result;
}
