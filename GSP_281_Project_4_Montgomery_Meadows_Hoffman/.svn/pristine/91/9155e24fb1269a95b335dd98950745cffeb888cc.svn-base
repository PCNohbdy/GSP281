#ifndef SPAWNER_H
#define SPAWNER_H
#include "ObjectManager.h"


class Spawner
{
public:
	enum TYPE{CANNONBALLS,FIREWORKS,BOX_STATIC,BOX_DYNAMIC,BOX_ANGULAR_DYNAMIC,BOX_ANGULAR_STATIC};
	Spawner();
	Spawner(Vector2 pos, float Vel, float angle, float MaxTime,COLORREF color, TYPE t);
	~Spawner();
	void Update(float dt);
	void ChangeMaxTime(float t);
	TYPE GetType(void) {return type;}
private:
	float Angle;
	float Vel;
	Vector2 pos;
	float time;
	float MaxTime;
	TYPE type;
	COLORREF color;
};
#endif