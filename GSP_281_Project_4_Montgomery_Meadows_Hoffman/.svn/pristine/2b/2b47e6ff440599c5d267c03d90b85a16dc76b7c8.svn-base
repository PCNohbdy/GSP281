#include "Planner.h"

Planner* Planner::Instance()
{
	static Planner* PlannMan = new Planner();
	return PlannMan;
}

Planner::Planner( )
{

}

Planner::~Planner( )
{

}

void Planner::RemoveTableWrap(TableWraps* TW)
{
	for(unsigned int x = 0; x < M_TableWraps.size( ); ++x)
	{
		if(M_TableWraps[x] = TW)
		{
			M_TableWraps.erase(M_TableWraps.begin() + x);
			break;
		}
	}
}

void Planner::RemoveGuestGroup(GuestGroup* GG)
{
	for(std::list<GuestGroup*>::iterator it = M_GuestGroupLine.begin(); it != M_GuestGroupLine.end( ); ++it)
	{
		if(*it = GG)
		{
			M_GuestGroupLine.erase(it);
			break;
		}
	}
}

void Planner::RemoveFood(Food * f)
{
	for(std::list<Food*>::iterator it = M_FoodWaitQueue.begin(); it != M_FoodWaitQueue.end( ); ++it)
	{
		if(*it = f)
		{
			M_FoodWaitQueue.erase(it);
			break;
		}
	}
}
void Planner::RemoveDrinks(Drinks *d)
{
	for(std::list<Drinks*>::iterator it = M_DrinkWaitQueue.begin(); it != M_DrinkWaitQueue.end( ); ++it)
	{
		if(*it = d)
		{
			M_DrinkWaitQueue.erase(it);
			break;
		}
	}
}

void Planner::SetTables(const int TableSize)
{
	for(int i = 0; i < TableSize;++i)
	{
		AddTable(new Tables(Tables::TABLE));
	}
}
//Make sure when you call you check the size of the returned vector if the size is 0 then no tables were found.
std::vector<Tables*> Planner::GetTables(const int size)
{
	std::vector<Tables*> tb;
	int RemainingSize = size;
	for(unsigned int i = 0; i < M_Tables.size();++i)
	{

		if(M_Tables[i]->GetSize() == 4 && M_Tables[i]->GetTableState() == Tables::CLEAN)
		{
			tb.push_back(M_Tables[i]);
			RemainingSize -= 4;
		}
		if(RemainingSize <= 0)
			break;
	}
	if(RemainingSize <= 0)
		return tb;
	else
	{
		tb.clear();
		return tb;
	}
}