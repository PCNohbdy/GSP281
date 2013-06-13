#include "GlobalData.h"
#include "Interface.h"

GlobalData::GlobalData() {
	//
}

void GlobalData::clear() {
	year_num = cook_num = waiter_num = table_num = 0;
	time_total = profit_average = cook_time_idle = waiter_time_idle = table_time_idle = 0;
}

void GlobalData::init(int years,int cooks,int waiters,int tables) {
	clear();
	year_num = years;
	cook_num = cooks;
	waiter_num = waiters;
	table_num = tables;
}
