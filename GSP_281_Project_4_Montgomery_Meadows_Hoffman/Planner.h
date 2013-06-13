#ifndef PLANNER_H
#define PLANNER_H

#include <vector>
#include <list>
#include "Food.h"
#include "Tables.h"
#include "TableWraps.h"
#include "GuestGroup.h"
#include "Drinks.h"
#define PM Planner::Instance()
class Planner
{
public:
	static Planner* Instance();
	~Planner();
	inline void AddTableWrap(TableWraps* TW){M_TableWraps.push_back(TW);}
	void RemoveTableWrap(TableWraps* TW);
	inline void AddGuestGroup(GuestGroup* GG){M_GuestGroupLine.push_back(GG);}
	void RemoveGuestGroup(GuestGroup* GG);
	inline void AddFood(Food * f){M_FoodWaitQueue.push_back(f);}
	void RemoveFood(Food *f);
	inline void AddDrinks(Drinks *d){M_DrinkWaitQueue.push_back(d);}
	void RemoveDrinks(Drinks *d);
	inline void AddTable(Tables* t){M_Tables.push_back(t);}
	void SetTables(const int TableSize);
	std::vector<Tables*> GetTables(const int size);

private:
	Planner();
	std::vector<Tables*> M_Tables;
	std::vector<TableWraps*> M_TableWraps;
	std::list<Food*> M_FoodWaitQueue;
	std::list<Drinks*> M_DrinkWaitQueue;
	std::list<GuestGroup*> M_GuestGroupLine;

};

#endif