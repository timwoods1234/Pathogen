#ifndef __LEVELEDITORSTORAGE_H__
#define __LEVELEDITORSTORAGE_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class LevelEditorStorage
{
public:
	LevelEditorStorage();

	~LevelEditorStorage();

	void OpenSaveDialog();

	void OpenLoadDialog();

private:
	void Load(const char* filename);

	void Save(const char* filename);
};

#endif
