#pragma once

#include "EDITDATA.h"

struct EVENTACTIONDATA : public EDITDATA
{
	DWORD this_3 = 0;
	DWORD this_4 = 0;
	virtual void init(FileReader& fw);
	virtual void dump([[maybe_unused]] FileWriter& fw) const;
};