#pragma once

#include "../Classes/EDITDATA.h"

struct VARIABLEACTION : public EDITDATA
{
	DWORD this_3 = 0;
	DWORD this_4 = 0;
	DWORD this_5 = 0;
	DWORD this_6 = 0;
	DWORD this_7 = 0;
	DWORD this_8 = 0;

	void init(FileReader& fw);
	virtual void dump([[maybe_unused]] FileWriter& fw) const;
};
