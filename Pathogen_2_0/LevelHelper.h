#ifndef __LEVELHELPER_H__
#define __LEVELHELPER_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class LevelHelper
{
public:
	static TVector2 World3ToGrid2(const TVector3& worldPosition);

	static TVector3 Grid2ToWorld3(const TVector2& gridPosition);

	static TVector2 Grid2ToWorld2(const TVector2& gridPosition);
};

#endif
