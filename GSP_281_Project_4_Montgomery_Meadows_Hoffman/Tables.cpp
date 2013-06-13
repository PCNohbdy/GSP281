#include "Tables.h"

Tables::Tables(TABLETYPE t)
{
	M_TableState = Tables::CLEAN;
	M_TableType = t;
	if(t == Tables::BOOTH)
	{
		M_Size = 6;
	}
	else if(t == Tables::STOOL)
	{
		M_Size = 2;
	}
	else if(t == Tables::TABLE)
	{
		M_Size = 4;
	}
}