#include "LevelEditorStorage.h"
#include "LevelEditor.h"
#include "LevelEditorEntry.h"
#include "LevelEditorEntryList.h"

//-------------------------------------------------------------------------------
LevelEditorStorage::LevelEditorStorage()
{
}

//-------------------------------------------------------------------------------
LevelEditorStorage::~LevelEditorStorage()
{
}

//-------------------------------------------------------------------------------
void LevelEditorStorage::OpenSaveDialog()
{
	TString selectedFile = TString::GetEmptyString();

	TLocator::GetFileSystem()->OpenFileBrowser(false, selectedFile);

	if (!selectedFile.IsEmpty())
	{
		Save(selectedFile.GetPointer());
	}
	else
	{
		TDebugPrint(("[LevelEditorStorage::OpenLoadDialog] failed to find file"));
	}
}

//-------------------------------------------------------------------------------
void LevelEditorStorage::OpenLoadDialog()
{
	TString selectedFile = TString::GetEmptyString();

	TLocator::GetFileSystem()->OpenFileBrowser(true, selectedFile);

	if (!selectedFile.IsEmpty())
	{
		Load(selectedFile.GetPointer());
	}
	else
	{
		TDebugPrint(("[LevelEditorStorage::OpenLoadDialog] failed to find file"));
	}
}

//-------------------------------------------------------------------------------
void LevelEditorStorage::Load(const char* filename)
{
	LevelEditor::Get()->Reset();

	LevelEditorEntryList* currentLevel = LevelEditor::Get()->GetEntryList();

	TXMLReader reader(filename, *currentLevel);

	TASSERT(!reader.WasError(), "[LevelEditorStorage::Load] Failed to open file");
}

//-------------------------------------------------------------------------------
void LevelEditorStorage::Save(const char* filename)
{
	LevelEditorEntryList* currentLevel = LevelEditor::Get()->GetEntryList();

	TXMLWriter writer(filename, "Level", *currentLevel);
}