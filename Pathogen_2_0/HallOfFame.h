#ifndef __HALLOFFAME_H__
#define __HALLOFFAME_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

#ifndef __HALLOFFAMEENTRY_H__
#include "HallOfFameEntry.h"
#endif

class HallOfFame : public TSingleton<HallOfFame>,
				   public TXMLObject
{
public:
	HallOfFame();

	unsigned int GetNumEntries() const;

	const HallOfFameEntry* GetEntry(unsigned int index) const;

	void AddEntry(const TString& playerName, int totalScore);

	bool IsScoreWorthy(int score) const;

	const TString& GetCurrentName() const;

	void SetCurrentName(const TString& name);

	void SortEntries();

	TXMLObject* HandleLoadElement(const TString& strID, TDynamicSet<TDataVariant>& objects);

	void HandleLoadAttributes(TDynamicSet<TDataVariant>& objects);

	void FinaliseLoad();

	void Write(TXMLWriter& writer);

	void Save();

private:
	TDynamicSet<HallOfFameEntry> m_hallOfFameEntries;

	TString m_currentName;
};

#endif
