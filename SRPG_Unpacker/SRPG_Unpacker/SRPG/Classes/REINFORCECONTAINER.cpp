// Compatible up to v1.292

#include "EDITDATA.h"
#include "../CMenuOperation.h"
#include "REINFORCECONTAINER.h"

void REINFORCECONTAINER::init(FileReader& fw)
{
	this_3 = fw.ReadDWord();
	this_4 = fw.ReadDWord();
	allocAndSetCMenuOp(&pReinforceData, SRPGClasses::REINFORCEDATA, fw);
}

void REINFORCECONTAINER::dump(FileWriter& fw) const
{
	fw.Write(this_3);
	fw.Write(this_4);
	pReinforceData->dump(fw);
}