#include "Sprite.h"
#include "CollisionManager.h"
//Constructor
Square::Square(Vector2 pos, float size,float mass,float vel,float angle, COLORREF color, float E):Sprite(angle)
{
	Pt = pos;
	this->elasticity = E;
	this->Mass = mass;
	this->size.x = size;
	this->size.y = size;
	this->color = color;
	this->vel.x = vel*std::cos(angle);
	this->vel.y = vel*std::sin(angle);
	this->t = 1;
	CollisionType = NOCOLLISION;
}
Square::Square(Vector2 pos, float size, float vel, float angle, float textureangle, Vector2 &scale, Vector2 &Orgion, COLORREF color, float E) : Sprite(angle, textureangle,scale,Orgion)
{
	Pt = pos;
	this->elasticity = E;
	this->size.x = size;
	this->size.y = size;
	this->color = color;
	this->vel.x = vel*std::cos(angle);
	this->vel.y = vel*std::sin(angle);
	this->t = 1;
	CollisionType = NOCOLLISION;
}
Square::Square(Vector2 pos,const Vector2 &size, float vel, float angle, float textureangle,float mass, Vector2 &scale, Vector2 &Orgion, COLORREF color,float E, TYPE t) : Sprite(angle, textureangle,scale,Orgion)
{
	Pt = pos;
	this->elasticity = E;
	this->size = size;
	this->color = color;
	this->vel.x = vel*std::cos(angle);
	this->vel.y = vel*std::sin(angle);
	this->t = 1;
	this->CollisionType = t;
	this->Mass = mass;
}
Square::~Square()
{
}
//Setting the size
void Square::SetSize(float x, float y)
{
	this->size.x = x;
	this->size.y = y;
}
//Draw Function
void Square::Render(void)
{
	if(CollisionManager::GetDebug())
	{
		if(CollisionType != NOCOLLISION)
		{
			Circle c(Pt,CollisionManager::FindSquareRadius(size),RGB(255,255,255));
			c.Render();
		}
	}
	UpdateAxis();
	//top bar
	Vector2 pt1,pt2;
	//The Orgion of the 2 points
	pt1.x = -(size.x/2);
	pt1.y = (size.y/2);
	pt2.x = (size.x/2);
	pt2.y = pt1.y;
	//rot.RotDeg(this->TextureAngle);
	//scale.Scale(this->Scale.x,this->Scale.y);
	//pt1 = rot * scale * pt1;
	//pt1 = trans * pt1;
	//pt2 = rot*scale*pt2;
	//pt2 = trans * pt2;
	Line ln(PointMath(pt1),PointMath(pt2),color);
	ln.Render();
	//right bar
	pt1.x = pt2.x;
	pt1.y = -(size.y)/2;
	//pt1 = rot*scale*pt1;
	//pt2 = rot*scale*pt2;
	ln.SetPoints(PointMath(pt1),PointMath(pt2));
	ln.Render();
	//bottom bar
	pt2.x = -size.x/2;
	pt2.y = pt1.y;
	//pt1 = rot*scale*pt1;
	//pt2 = rot*scale*pt2;
	ln.SetPoints(PointMath(pt1),PointMath(pt2));
	ln.Render();
	//left bar
	pt1.x = pt2.x;
	pt1.y =size.y/2;
	//pt1 = rot*scale*pt1;
	//pt2 = rot*scale*pt2;
	ln.SetPoints(PointMath(pt1),PointMath(pt2));
	ln.Render();
}
//Check Collision against circle
float Square::CheckCollision(const Circle &cir) const
{

	return CollisionManager::CheckCollision(*this,cir);
}
float Square::CheckCollision(const Vector2 &vect) const
{
	return CollisionManager::CheckCollision(*this,vect);
}
//Check Collision against another square
float Square::CheckCollision(const Square &sqr) const
{	
	return CollisionManager::CheckCollision(*this,sqr);
}
float Square::CheckCollision(const Sprite &spr)const
{
	return spr.CheckCollision(*this);
}
//Get Collision pen for square
float Square::GetCollisionPen(const Square &sqr) const
{

	return 1;
}
//Get Collision Pen for circle
float Square::GetCollisionPen(const Circle &cir) const
{
	return 1;
}
void Square::ResolveCollision(Sprite &spr, float pen)
{
	spr.ResolveCollision(*this,pen);
}
void Square::ResolveCollision(Circle &cir, float pen)
{
	CollisionManager::ResolveCollision(*this,cir,pen);
}
void Square::ResolveCollision(Square &sqr, float pen)
{
	CollisionManager::ResolveCollision(*this,sqr,pen);
}
//update The vel
void Square::Update(float dt)
{
	Pt += vel;
	vel += Gravity;
	Orgion = Pt;
	//vel = vel * .98f ;
	TextureAngle += AngVel;
	AngVel *= .98f;
}
//Update Screen Collision
void Square::UpdateScreenCollision(int minx, int maxx,int miny,int maxy)
{
	if(Pt.x - (this->size.x/2) < minx*1.5)
	{
		this->collision = true;
		Pt.x = (float)(minx + (size.x/2));
		this->vel.x *= -1;
	}
	else if(Pt.x + (this->size.x/2) > maxx*3)
	{
		this->collision = true;
		Pt.x = (float)(maxx - (size.x/2));
		this->vel.x *= -1;
	}
	if(Pt.y - (this->size.y/2) < miny*1.5)
	{
		this->collision = true;
		Pt.y = (float)(miny + (size.y/2));
		this->vel.y *= -1;
	}
	else if(Pt.y + (this->size.y/2) > maxy*3)
	{
		this->collision = true;
		Pt.y = (float)(maxy - (size.y/2));
		this->vel.y *= -1;
	}
}