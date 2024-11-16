#ifndef __LEVELLOADER_H__
#define __LEVELLOADER_H__

class LevelEditorEntryList;
class LevelEditorEntry;

class LevelLoader
{
public:
	LevelLoader();

	~LevelLoader();

	void Load(const char* filename);

private:
	void LoadEntries(const LevelEditorEntryList* entryList);

	void LoadEntry(const LevelEditorEntry* entry);
};

#endif
