#include "AISharedFunctions.h"

//-------------------------------------------------------------------------------
TVector2 AISharedFunctions::GetRandomDirection()
{
	static unsigned int seed = 12345;
	TVector2 result = GetRandomUnitVec2(&seed);

	// TODO: make sure it isn't zero

	result.Normalize();

	return result;
}