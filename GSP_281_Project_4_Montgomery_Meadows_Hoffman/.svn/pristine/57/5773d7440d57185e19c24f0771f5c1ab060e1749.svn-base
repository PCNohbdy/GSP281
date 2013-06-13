#include "Spawner.h"
Spawner::Spawner()
{
	this->pos = Zero();
	Angle = 0.0f;
	Vel = 0.0f;
	MaxTime = 0.0f;
	time = MaxTime;
	type = this->FIREWORKS;
	this->color = RGB(0,0,0);
}
Spawner::Spawner(Vector2 pos, float vel, float angle, float MaxTime,COLORREF color, TYPE t)
{
	this->pos = pos;
	Angle = angle;
	Vel = vel;
	this->MaxTime = MaxTime;
	this->time = MaxTime;
	this->type = t;
	this->color = color;
}

Spawner::~Spawner()
{
}
void Spawner::Update(float dt)
{
	time -= dt;
	if(time <= 0)
	{
		COLORREF yellow = RGB(255,255,0);
		if(type == this->FIREWORKS)
			OM->GetObjectVector().push_back(new Firework(-1.0f,pos,15,Vel,Angle,color));
		else if(type == this->CANNONBALLS)
			OM->GetObjectVector().push_back(new Circle(pos,20,10,Vel,Angle+(std::rand()%20 -10),color));
		else if(type == this->BOX_ANGULAR_DYNAMIC)
			OM->GetObjectVector().push_back(new Square(pos,Vector2D(100.0f,20.0f),Vel,Angle,0,10,Vector2D(1.0f,1.0f),pos,color,.8f,Sprite::DYNAMIC_ANGULAR));
		else if(type == this->BOX_ANGULAR_STATIC)
			OM->GetObjectVector().push_back(new Square(pos,Vector2D(100.0f,20.0f),Vel,Angle,0,10,Vector2D(1.0f,1.0f),pos,color,.8f,Sprite::STATIC_ANGULAR));
		else if(type == this->BOX_DYNAMIC)
			OM->GetObjectVector().push_back(new Square(pos,Vector2D(100.0f,20.0f),Vel,Angle,0,10,Vector2D(1.0f,1.0f),pos,color,.8f,Sprite::DYNAMIC_LINEAR));
		else if(type == this->BOX_STATIC)
			OM->GetObjectVector().push_back(new Square(pos,Vector2D(100.0f,20.0f),Vel,Angle,0,10,Vector2D(1.0f,1.0f),pos,color,.8f,Sprite::STATIC));

		time = MaxTime;
	}
}
void Spawner::ChangeMaxTime(float t)
{
	MaxTime = t;
	time = 0.0f;
}
