#ifndef __OPTIONS_H__
#define __OPTIONS_H__

#ifndef __TENGINEINCLUDED_H__
#include "TEngine.h"
#endif

class Options : public TSingleton<Options>,
				public TXMLObject
{
public:
	Options();

	~Options();

	bool GetAutoFire() const;

	void SetAutoFire(bool enable);

	TXMLObject* HandleLoadElement(const TString& strID, TDynamicSet<TDataVariant>& objects);

	void HandleLoadAttributes(TDynamicSet<TDataVariant>& objects);

	void FinaliseLoad();

	void Write(TXMLWriter& writer);

	void Save();

private:
	bool m_autoFire;
};

#endif
