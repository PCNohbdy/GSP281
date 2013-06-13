#ifndef PARTICLE_H
#define PARTICLE_H

#include "Sprite.h"

template<class T>
class Particle: public T
{
public:
	Particle(Vector2 pos,float size,float vel,float angle,float life, COLORREF color);
	~Particle();
	virtual void Update(float dt);
protected:
	float life;
	float MaxLife;
};
#include "Particle.cpp"
#endif