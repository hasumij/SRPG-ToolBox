#pragma once

#include "../Classes/EDITDATA.h"

struct HPRECOVERY : public EDITDATA
{
	std::array <DWORD, 7> m_data;
	virtual void init(FileReader& fw);
	virtual void dump([[maybe_unused]] FileWriter& fw) const;
};