#ifndef __LEVELEDITORENTRYLIST_H__
#define __LEVELEDITORENTRYLIST_H__

// TODO: remove editor from the name? move to level folder?

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

#ifndef __LEVELEDITORENTRY_H__
#include "LevelEditorEntry.h"
#endif

class LevelEditorEntryList : public TXMLObject
{
public:
	LevelEditorEntryList();

	~LevelEditorEntryList();

	void ClearAllEntries();

	unsigned int GetNumEntries() const;

	const LevelEditorEntry* GetEntry(unsigned int index) const;

	const LevelEditorEntry* GetEntry(const TVector2& position) const;

	void AddEntry(LevelEditorEntry& entry);

	void RemoveEntry(const LevelEditorEntry& entry);

	TXMLObject* HandleLoadElement(const TString& strId, TDynamicSet<TDataVariant>& objects);

	void HandleLoadAttributes(TDynamicSet<TDataVariant>& objects);

	void FinaliseLoad();

	void Write(TXMLWriter& writer);

private:
	TDynamicSet<LevelEditorEntry*> m_entries;
};

#endif
