#ifndef DRINKS_H
#define DRINKS_H

class Drinks
{
public:
	enum STATE{STARTED,FINISHED};
	enum TYPE{WATER,TEA,SODA};
	Drinks(TYPE t);
	~Drinks();
	inline float GetCost(void){return M_Cost;};
	inline STATE GetState(void){return M_State;};
	inline float SetState(STATE s){M_State = s;}
private:
	float M_Cost,
	M_MinPrepTime, M_MaxPrepTime;
	STATE M_State;
	TYPE M_Type;
};



#endif