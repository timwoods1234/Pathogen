#include "LevelList.h"

//-------------------------------------------------------------------------------
LevelList::LevelList()
{
	LoadLevelNames();
}

//-------------------------------------------------------------------------------
LevelList::~LevelList()
{
}

//-------------------------------------------------------------------------------
unsigned int LevelList::GetNumLevels() const
{
	return m_levelNames.GetSize();
}

//-------------------------------------------------------------------------------
const TString& LevelList::GetLevelName(unsigned int index) const
{
	return m_levelNames[index];
}

//-------------------------------------------------------------------------------
void LevelList::LoadLevelNames()
{
	TLocator::GetFileSystem()->GetFileList("Assets/Data/Levels", "xml", m_levelNames);
}
