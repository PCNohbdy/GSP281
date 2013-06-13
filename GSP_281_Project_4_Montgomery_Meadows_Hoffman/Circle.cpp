#include "Sprite.h"
#include <cmath>
#include "CollisionManager.h"
extern GraphicsFramework *PGraphics;
using namespace std;
//Constructors
Circle::Circle(Vector2 vect1,Vector2 vect2,COLORREF color) : Sprite(0)
{
	this->Pt = vect1;
	this->SetRadius(vect2);
	this->color = color;
	vel.x = 0;
	vel.y = 0;
	this->t = 2;
	Gravity = Vector2D((float)0,(float)-.1);
}
//Constructor
Circle::Circle(Vector2 vect1,float radius,COLORREF color) : Sprite(0)
{
	this->Pt = vect1;
	this->radius = radius;
	this->color = color;
	vel.x = 0;
	vel.y = 0;
	this->t = 2;
}
//Constructor
Circle::Circle(Vector2 vect1, float radius,float mass, float vel,float angle, COLORREF color):Sprite(angle)
{
	this->Pt = vect1;
	this->radius = radius;
	this->color = color;
	this->vel.x = vel * (float)std::cos((angle*3.14)/180);
	this->vel.y = vel * (float)std::sin((angle*3.14)/180);
	this->t = 2;
	this->Mass = mass;
	this->elasticity = (float).8;
	Gravity = Vector2D((float)0,(float)-.1);
}
//Constructor
Circle::Circle(Vector2 pos, COLORREF color, HBITMAP *texture, float radius,float scale, float vel, float angle,float mass, float elasticity):Sprite(angle)
{
	Pt = pos;
	this->color = color;
	this->radius = radius;
	this->vel.x = vel * (float)std::cos((angle*3.14)/180);
	this->vel.y = vel * (float)std::sin((angle*3.14)/180);
	this->Mass = mass;
	this->elasticity = elasticity;
	this->t = 2;
	this->texture = texture;
	Gravity = Vector2D((float)0,(float)-.1);
	if(texture != NULL)
		hBrush = CreatePatternBrush(*(this->texture));
}
//Destructor
Circle::~Circle()
{
	DeleteObject(hBrush);
}
//Set the radius
void Circle::SetRadius(Vector2 const &pt)
{
	radius = (float)sqrt((float)((pt.x - Pt.x)*(pt.x - Pt.x)) + (float)((pt.y - Pt.y)*(pt.y - Pt.y)));
}
//drawing the circle using the midpoint circle algorithm

void Circle::Render(void)
{
	UpdateAxis();
	if(texture != NULL)
	{
		RECT rect = PGraphics->GetRect((int)Pt.x,(int)Pt.y,(int)(this->radius));
		Vector2 pt2;
		pt2.x = -Pt.x;
		pt2.y = -Pt.y;
		RECT rect1 = PGraphics->GetRect((int)pt2.x,(int)pt2.y,(int)(this->radius));
		PGraphics->DrawAnimatedBMP(*texture,rect,rect1,hBrush);
	}
	else
	{
	//the deciding variable if we need to subtract from the y
	int radius = (int)(this->radius * Scale.x);
	int d = 1 - radius;

    int dfx = 1;
    int dfy = -2 * radius;
	int x = 0;
	int y = radius;
	int x1 = static_cast<int> (Pt.x);
	int y1 = static_cast<int> (Pt.y);

	//Draws the 4 dots to the circle. Top,Left,Bottom,Right
	PGraphics->AddPoint(x1,y1 + radius,color);
	PGraphics->AddPoint(x1,y1 - radius,color);
	PGraphics->AddPoint(x1 + radius,y1,color);
	PGraphics->AddPoint(x1 - radius,y1,color);
	//keep looping till x = y or x > y
	//if south is selected then it moves south and east.
	while(x < y)
	{
		//if pixel is outside or on the boundry of the cirle
		//only moves south
		if(d >= 0)
		{
			--y;
			dfy += 2;
			d += dfy;
		}
		//if the pixel is inside the circle
		//only moves east 
		++x;
		dfx += 2;
		d += dfx;
		//drawing 8 pixels at 1 time.
		PGraphics->AddPoint(x1 + x,y1 + y,color);
		PGraphics->AddPoint(x1 + x,y1 - y,color);
		PGraphics->AddPoint(x1 - x,y1 + y,color);
		PGraphics->AddPoint(x1 - x,y1 - y,color);
		PGraphics->AddPoint(x1 - y,y1 + x,color);
		PGraphics->AddPoint(x1 - y,y1 - x,color);
		PGraphics->AddPoint(x1 + y,y1 + x,color);
		PGraphics->AddPoint(x1 + y,y1 - x,color);
		}
	}

}
//Circle Circle Collision
float Circle::CheckCollision(const Circle &cir) const
{
	//Make sure your not checking against yourself
	return CollisionManager::CheckCollision(*this,cir);
}
//Get the penitration amount
float Circle::GetCollisionPen(const Circle &cir) const
{
	float totalradius = (float)this->radius + cir.GetRadius();
	Vector2 vect1 = cir.GetPosition();
	float dist =std::sqrt(std::pow(vect1.y- this->Pt.y,2) + std::pow(vect1.x - Pt.x,2));
	dist -= totalradius;
	return -dist;
}
//Holder for sqare inner pen amount
float Circle::GetCollisionPen(const Square &sqr) const
{
	return 1;
}
void Circle::ResolveCollision(Sprite &spr, float pen)
{
	spr.ResolveCollision(*this,pen);
}
void Circle::ResolveCollision(Square &sqr, float pen)
{
	CollisionManager::ResolveCollision(*this,sqr,pen);
}
void Circle::ResolveCollision(Circle &cir, float pen)
{
	CollisionManager::ResolveCollision(*this,cir,pen);
}
float Circle::CheckCollision(const Vector2 &vect)const
{
	return CollisionManager::CheckCollision(*this,vect);
}
float Circle::CheckCollision(const Sprite &sprite)const
{
	return sprite.CheckCollision(*this);
}
//Circle Square collision
float Circle::CheckCollision(const Square &sqr) const
{
	return CollisionManager::CheckCollision(*this,sqr);
}
//Update Circle
void Circle::Update(float dt)
{
	Pt += this->vel;
	//this->vel += Gravity;
	this->Orgion = Pt;
	this->AngVel = this->AngVel * .98f;
}
//Update Screen Circle Collision
void Circle::UpdateScreenCollision(int minx, int maxx,int miny,int maxy)
{
	if(Pt.x - (this->radius) < minx*1.5)
	{
		collision = true;
		Pt.x = (float)(minx + (radius));
		vel.x *= -1;
	}
	else if(Pt.x + (this->radius) > maxx*1.5)
	{
		collision = true;
		Pt.x = (float)(maxx - (radius));
		vel.x *= -1;
	}
	if(Pt.y - (this->radius) < miny*1.5)
	{
		collision = true;
		Pt.y = (float)(miny + (radius));
		vel.y *= -1;
	}
	else if(Pt.y + (this->radius) > maxy*1.5)
	{
		collision = true;
		Pt.y = (float)(maxy - (radius));
		vel.y *= -1;
	}
}