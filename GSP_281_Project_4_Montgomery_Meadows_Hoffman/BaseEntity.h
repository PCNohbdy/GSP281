#ifndef BASEENTITY_H
#define BASEENTITY_H
#include "Vector3.h"
class BaseEntity
{
public:
	enum TYPE{NOCOLLISION,STATIC,DYNAMIC_LINEAR,DYNAMIC_ANGULAR,STATIC_ANGULAR};
	BaseEntity();
	~BaseEntity();
	virtual void Update(void) = 0;
	bool	GetDestroy()const{return M_Destroy;}
	Vector3 GetPosition()const{return M_Pos;}
	Vector3 GetVel()const{return M_Vel;}
	Vector3 GetAcceleration()const{return M_Acceleration;}
	TYPE	GetCollisionType()const{return M_CollisionType;}
	Vector3 SetPosition(Vector3 &vect){M_Pos = vect;}
	Vector3 SetVel(Vector3 &vect){M_Vel = vect;}
	Vector3 SetAcceleration(Vector3 &vect){M_Acceleration = vect;}
protected:
	TYPE M_CollisionType;
	int M_id;
	bool M_Destroy;
	float Mass;
	Vector3 M_Pos,M_Vel,M_Acceleration;
};
#endif