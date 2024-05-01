#pragma once

#include "EDITDATA.h"

struct IMAGEDATA : public EDITDATA
{
	MemData this_3;
	DWORD this_4 = 0;
	virtual void init(FileReader& fw);
	virtual void dump([[maybe_unused]] FileWriter& fw) const;

protected:
	nlohmann::ordered_json toJson() const override;
};