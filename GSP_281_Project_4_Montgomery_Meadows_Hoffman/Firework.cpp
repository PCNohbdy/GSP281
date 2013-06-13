#include "Firework.h"
#include "ObjectManager.h"
Firework::Firework(float life, Vector2 pos,float radius, float vel, float anglevel, COLORREF color) : Circle(pos,radius,10,vel,anglevel,color)
{
	this->life = life;
	this->CollisionType = this->NOCOLLISION;
}
Firework::~Firework()
{

}
void Firework::Update(float dt)
{
	this->vel += Gravity;
	this->Pt += vel;
	OM->AddCircleParticles(1,this->Pt,color);
	OM->AddSquareParticles(1,this->Pt,color);
	if(life != -1)
	{
		life -= dt;
		if(life <=0)
		{
			OM->AddCircleParticles(30,this->Pt,color);
			OM->AddSquareParticles(30,this->Pt,color);
			this->collision = true;
		}
	}
	else if(vel.y < 0)
	{
		OM->AddCircleParticles(30, this->Pt,color);
		OM->AddSquareParticles(30, this->Pt,color);
		this->collision = true;
	}
}