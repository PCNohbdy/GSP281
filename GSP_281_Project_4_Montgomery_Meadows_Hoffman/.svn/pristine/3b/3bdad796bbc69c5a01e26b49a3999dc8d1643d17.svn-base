#include "Food.h"


Food::Food(TYPE t)
{
	M_Type = t;
	M_State = RAW;
	if(t == Food::BURRITO)
	{
		M_Cost = 7.50f - .75f;
		M_MinCookTime = 3;
		M_MaxCookTime = 5;
	}
	else if(t == Food::BEEFFAJITAS)
	{
		M_Cost = 9.0f - 1.5f;
		M_MinCookTime = 7;
		M_MaxCookTime = 8;
	}
	else if(t == Food::ENCHILADA)
	{
		M_Cost = 6.50f - 1.0f;
		M_MinCookTime = 4;
		M_MaxCookTime = 6;
	}
	else if(t == Food::CHICKENFAJITAS)
	{
		M_Cost = 15.0f - 3.0f;
		M_MinCookTime = 7;
		M_MaxCookTime = 12;
	}
	else if(t == Food::TACOPLATE)
	{
		M_Cost = 6.50f - .75f;
		M_MinCookTime = 4;
		M_MaxCookTime = 6;
	}
	else if(t == Food::TACOCARBON)
	{
		M_Cost = 5.0f - 1.0f;
		M_MinCookTime = 3;
		M_MaxCookTime = 5;
	}
	else if(t == CHILEVERDE)
	{
		M_Cost = 9.49f - 3.0f;
		M_MinCookTime = 4;
		M_MaxCookTime = 7;
	}
}
Food::~Food()
{

}