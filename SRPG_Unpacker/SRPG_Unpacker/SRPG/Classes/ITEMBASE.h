#pragma once

#include "EDITDATA.h"
#include "LEGENDDATA.h"

struct ITEMBASE : public EDITDATA, public LEGENDDATA
{
	DWORD res1 = 0;
	DWORD res2 = 0;

	DWORD this_8                         = 0;
	DWORD price                          = 0;
	DWORD uses                           = 0;
	DWORD weight                         = 0;
	DWORD paramBonusHp                   = 0;
	DWORD paramBonusStr                  = 0;
	DWORD paramBonusMag                  = 0;
	DWORD paramBonusSkl                  = 0;
	DWORD paramBonusSpd                  = 0;
	DWORD paramBonusLck                  = 0;
	DWORD paramBonusDef                  = 0;
	DWORD paramBonusRes                  = 0;
	DWORD paramBonusMov                  = 0;
	DWORD paramBonusWlv                  = 0;
	DWORD paramBonusBld                  = 0;
	DWORD grothBonusHp                   = 0;
	DWORD grothBonusStr                  = 0;
	DWORD grothBonusMag                  = 0;
	DWORD grothBonusSkl                  = 0;
	DWORD grothBonusSpd                  = 0;
	DWORD grothBonusLck                  = 0;
	DWORD grothBonusDef                  = 0;
	DWORD grothBonusRes                  = 0;
	DWORD grothBonusMov                  = 0;
	DWORD grothBonusWlv                  = 0;
	DWORD grothBonusBld                  = 0;
	DWORD this_34                        = 0;
	DWORD this_35                        = 0;
	DWORD this_36                        = 0;
	DWORD this_37                        = 0;
	class CMenuOperation* m_pTypeIDData1 = nullptr;
	DWORD this_39                        = 0;
	class CMenuOperation* m_pTypeIDData2 = nullptr;
	MemData this_41;
	DWORD this_42 = 0;
	MemData this_43;

	virtual void init(FileReader& fw);
	virtual void dump([[maybe_unused]] FileWriter& fw) const;
	virtual void print(std::ostream& os) const;

private:
	void sub_101AB0(FileReader& fw);
	void sub_36E310(FileReader& fw);
};
