#ifndef FOOD_H
#define FOOD_H



class Food
{
public:
	enum STATE{RAW,COOKED};
	enum TYPE{TACOPLATE,TACOCARBON,BURRITO,CHICKENFAJITAS,BEEFFAJITAS,ENCHILADA,TAMALE,CHILEVERDE};
	Food(TYPE t);
	~Food();
	inline float GetCost(void){return M_Cost;};
	inline STATE GetState(void){return M_State;};
	inline void  SetState(STATE s){M_State = s;};
private:
	float M_Cost;
	float M_MinCookTime,M_MaxCookTime;
	STATE M_State;
	TYPE M_Type;
};



#endif