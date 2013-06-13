#include "Sprite.h"
#define PI 3.1415927
#define EPSON .0001
//Constructor
Sprite::Sprite(float angle)
{
	this->angle = angle;
	this->TextureAngle = 0.0f;
	this->Orgion = Zero();
	this->Transpose = Zero();
	this->collision = false;
	this->vel = Zero();
	this->Scale.x = 1.0f;
	this->Scale.y = 1.0f;
	this->texture = NULL;
	this->CollisionType = this->DYNAMIC_LINEAR;
	AngVel = 0;
	Gravity = Zero();
}
//Constructor
Sprite::Sprite(float angle,float textangle,Vector2 scale)
{
	this->angle = angle;
	this->TextureAngle = textangle;
	this->Scale = scale;
	this->Orgion = Zero();
	this->Transpose = Zero();
	this->collision = false;
	this->vel = Zero();
	this->texture = NULL;
	this->CollisionType = this->DYNAMIC_LINEAR;
	AngVel = 0;
	Gravity = Zero();
}
//Constructor
Sprite::Sprite(float angle,float textangle,Vector2 scale, Vector2 Orgion)
{
	this->angle = angle;
	this->TextureAngle = textangle;
	this->Scale = scale;
	this->Orgion = Orgion;
	this->Transpose = Zero();
	this->collision = false;
	this->vel = Zero();
	this->texture = NULL;
	this->CollisionType = this->DYNAMIC_LINEAR;
	AngVel = 0;
	Gravity = Zero();
}
//Constructor
Sprite::Sprite(float angle,float textangle,Vector2 scale, Vector2 Orgion, Vector2 Trans)
{
	this->angle = angle;
	this->TextureAngle = textangle;
	this->Scale = scale;
	this->Orgion = Orgion;
	this->Transpose = Trans;
	this->collision = false;
	this->vel = Zero();
	this->texture = NULL;
	this->CollisionType = this->DYNAMIC_LINEAR;
	AngVel = 0;
	Gravity = Zero();
}
//Matrix3 math
Vector2 Sprite::PointMath(const Vector2 &pt1)const
{
	Vector2 temp;
	temp.x = 1;
	temp.y =1;
	Matrix3 rot,trans,scale, orgion;
	trans.Identity();
	//Move the Object back to its origional location
	trans.Transpose(&Orgion);
	//Move the object to the orgion
	orgion.Transpose(&(Orgion - (Pt+pt1)));
	//Set up the scale
	scale.Scale(this->Scale.x,this->Scale.y);
	//Set up the angle
	rot.RotDeg(this->TextureAngle);
	//Rotate and scale the object by its orgion;
	temp = rot *scale* orgion * temp;
	//temp = scale * rot * orgion * pt1;
	//Move the object back
	temp = trans * temp;
	trans.Identity();
	trans.Transpose(&this->Transpose);
	temp = trans * temp;
	return temp;
}
//Set Position
void Sprite::SetPosition(const Vector2 &vect)
{
	Pt = vect;
}
void Sprite::UpdateAxis()
{
	float angle = (float)(TextureAngle * PI/180);
	this->M_Axis[0].x = std::cos(angle);
	if(M_Axis[0].x < EPSON && M_Axis[0].x > -EPSON)
		M_Axis[0].x = 0.0f;
	this->M_Axis[0].y = std::sin(angle);

	if(M_Axis[0].y < EPSON && M_Axis[0].y > -EPSON)
		M_Axis[0].y = 0.0f;
	this->M_Axis[1].x = -std::sin(angle);
	if(M_Axis[1].x < EPSON && M_Axis[1].x > -EPSON)
		M_Axis[1].x = 0.0f;
	this->M_Axis[1].y = std::cos(angle);
	if(M_Axis[1].y < EPSON && M_Axis[1].y > -EPSON)
		M_Axis[1].y = 0.0f;
}
float Sprite::CollisionProject(const Vector2 &size,const Vector2 &vect) const
{
	return size.x * std::abs(M_Axis[0].Dot(vect)) + size.y * std::abs(M_Axis[1].Dot(vect));
}
//Update Collision
bool Sprite::UpdateCollision(std::vector<Sprite*> &sprt)
{
	return true;
}