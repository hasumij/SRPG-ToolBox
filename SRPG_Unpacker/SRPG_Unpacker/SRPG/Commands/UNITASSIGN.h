#pragma once

#include "../Classes/EDITDATA.h"

struct UNITASSIGN : public EDITDATA
{
	DWORD this_3 = 0;
	DWORD this_4 = 0;
	virtual void init(FileReader& fw);
	virtual void dump([[maybe_unused]] FileWriter& fw) const;
};
