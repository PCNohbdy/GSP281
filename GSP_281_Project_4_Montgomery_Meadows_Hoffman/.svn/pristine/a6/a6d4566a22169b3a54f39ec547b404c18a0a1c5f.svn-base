#ifndef BALL_H
#define BALL_H
#include "BaseEntity.h"

class Ball : public BaseEntity
{
public:
	Ball();
	~Ball();
	float GetRadius()const{return Radius;}
	void SetRadius(float f){Radius = f;}
	void Update(void);
	float CheckCollision(const Ball &ball2);
private:
	float Radius;
};


#endif