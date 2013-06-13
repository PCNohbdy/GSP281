#ifndef GLOBALDATA_H
#define GLOBALDATA_H

#include <iostream>
#include <fstream>

using namespace std;

class GlobalData {
public:
	GlobalData();

	void clear();
	void init(int years,int cooks,int waiters,int tables);

	int cook_num,
		waiter_num,
		table_num,
		year_num;
	
	double time_total,
		   profit_average,
		   cook_time_idle,
		   waiter_time_idle,
		   table_time_idle; //time not being used
};

#endif