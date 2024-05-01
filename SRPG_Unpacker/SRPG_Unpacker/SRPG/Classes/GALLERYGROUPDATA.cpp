// Compatible up to v1.292

#include "GALLERYGROUPDATA.h"

void GALLERYGROUPDATA::init(FileReader& fw)
{
	this_3 = fw.ReadDWord();
	this_4 = fw.ReadDWord();
	this_5 = fw.ReadDWord();
}

void GALLERYGROUPDATA::dump(FileWriter& fw) const
{
	fw.Write(this_3);
	fw.Write(this_4);
	fw.Write(this_5);
}