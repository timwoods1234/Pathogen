#ifndef __LEVELLIST_H__
#define __LEVELLIST_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class LevelList
{
public:
	LevelList();

	~LevelList();

	unsigned int GetNumLevels() const;

	const TString& GetLevelName(unsigned int index) const;

private:
	void LoadLevelNames();

	TDynamicSet<TString> m_levelNames;
};

#endif
