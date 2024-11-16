#include "LevelLoader.h"
#include "LevelEditorEntryList.h"
#include "LevelEditorEntry.h"
#include "Level.h"

//-------------------------------------------------------------------------------
LevelLoader::LevelLoader()
{
}

//-------------------------------------------------------------------------------
LevelLoader::~LevelLoader()
{
}

//-------------------------------------------------------------------------------
void LevelLoader::Load(const char* filename)
{
	LevelEditorEntryList* entryList = TNew LevelEditorEntryList();

	TXMLReader reader(filename, *entryList);

	if (!reader.WasError())
	{
		Level::Get()->Reset();

		LoadEntries(entryList);

		Level::Get()->AddPlayer();
	}

	TSafeDelete(entryList);
}

//-------------------------------------------------------------------------------
void LevelLoader::LoadEntries(const LevelEditorEntryList* entryList)
{
	for (unsigned int index = 0; index < entryList->GetNumEntries(); index++)
	{
		const LevelEditorEntry* entry = entryList->GetEntry(index);

		LoadEntry(entry);
	}
}

//-------------------------------------------------------------------------------
void LevelLoader::LoadEntry(const LevelEditorEntry* entry)
{
	// TODO: always egg type here?
	TEntity* entity = Level::Get()->CreateEntity(entry->GetDefinition(), EntityType::Egg);

	TASSERT((entity != NULL), "[LevelLoader::LoadEntry] bad entity definition");

	const TVector2& entryPosition = entry->GetPosition();

	TVector3 entityPosition(entryPosition.x, entryPosition.y, 0.f);
	entity->SetPosition(entityPosition);
}
