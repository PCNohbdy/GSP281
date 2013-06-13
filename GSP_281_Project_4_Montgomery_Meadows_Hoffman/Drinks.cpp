#include "Drinks.h"



Drinks::Drinks(TYPE t)
{
	this->M_Type = t;
	this->M_State = Drinks::STARTED;
	if(M_Type == WATER)
	{

	}
	else if(M_Type == SODA)
	{

	}
	else if(M_Type == TEA)
	{

	}
}