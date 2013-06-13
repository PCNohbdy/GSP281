#include "CollisionManager.h"
#include "GraphicsFramework.h"
#define PI 3.1415927
//Constructor
namespace CMName
{
	Vector2 CollisionPoint;
	bool DebugOn;
}
CollisionManager::CollisionManager()
{
}
//Destructor
CollisionManager::~CollisionManager()
{

}
void CollisionManager::Init(RECT rect)
{
	Screen.bottom = rect.bottom;
	Screen.right  = rect.right;
	Screen.left   = rect.left;
	Screen.top    = rect.top;
	CMName::DebugOn = false;
}
void CollisionManager::ToggleDebug()
{
	if(CMName::DebugOn)
		CMName::DebugOn = false;
	else
		CMName::DebugOn = true;
}
bool CollisionManager::GetDebug()
{
	return CMName::DebugOn;
}

void CollisionManager::Update(std::vector<Sprite*> &sprite)
{
	for(unsigned int i = 0; i < sprite.size(); ++i)
	{
		if(sprite[i]->GetCollisionType() == Sprite::NOCOLLISION)
			continue;
		if(i+1 <sprite.size())
		{
			for(unsigned int j = i+1; j < sprite.size(); ++j)
			{
				if(sprite[j]->GetCollisionType() == Sprite::NOCOLLISION)
					continue;
				//Detect Collision
				//if the sprite I am checking against is a circle
				//float pen = CheckCollision(sprite[i]->Get(),sprite[j]->Get());
				float pen = sprite[i]->CheckCollision(*sprite[j]);
				if(pen > 0)
				{
					//ResolveCollision(sprite[i]->Get(), sprite[j]->Get(),pen);
					Vector2 v;
					v.x = CMName::CollisionPoint.x;
					v.y = CMName::CollisionPoint.y;
					Circle c(v,10,RGB(255,255,255));
					c.Render();
					sprite[i]->ResolveCollision(*sprite[j],pen);
				}
			}
			sprite[i]->UpdateScreenCollision(Screen.left,Screen.right,Screen.bottom,Screen.top);
		}
	}
}
float CollisionManager::CheckCollision(const Sprite &spr1, const Sprite &spr2)
{
	return 0;
}
float CollisionManager::CheckCollision(const Circle &cir1, const Circle &cir2)
{
	float totalradius = cir1.GetRadius()+ cir2.GetRadius();
	Vector2 vect1 = cir2.GetPosition();
	Vector2 Pt = cir1.GetPosition();
	float dist = (float)std::sqrt(std::pow(vect1.y- Pt.y,2) + std::pow(vect1.x - Pt.x,2));
	return totalradius - dist;
}
float CollisionManager::CheckCollision(const Circle &cir, const Vector2 &vect)
{
	float d = cir.GetRadius() - (float)cir.GetPosition().Distance(vect);
	CMName::CollisionPoint = vect;
	return d;
}
float CollisionManager::CheckCollision(const Circle &cir, const Square &sqr)
{
	if(sqr.GetTextureAngle() != 0)
	{
		Circle c(sqr.GetPosition(),CollisionManager::FindSquareRadius(sqr.GetSize()),RGB(255,255,255));
		if(CollisionManager::CheckCollision(cir,c)<=0)
			return 0;
		Vector2 d = cir.GetPosition() - sqr.GetPosition();
		Vector2 q = sqr.GetPosition();
		Vector2 Ssize = sqr.GetSize()/2;
		float dist = d.Dot(sqr.GetAxis(0));
		if(dist > Ssize.x)
			dist = Ssize.x;
		else if(dist < -Ssize.x)
			dist = -Ssize.x;
		q = q + sqr.GetAxis(0) * dist;

		dist = d.Dot(sqr.GetAxis(1));

		if(dist > Ssize.y)
			dist = Ssize.y;
		else if(dist< -Ssize.y)
			dist = -Ssize.y;
		q = q + sqr.GetAxis(1) * dist;

		return CheckCollision(cir,q);
	}
	else
	{
		Vector2 p = cir.GetPosition();
		Vector2 Spt = sqr.GetPosition();
		Vector2 Ssize = sqr.GetSize()/2;
		if(p.x > Spt.x + Ssize.x)
			p.x = Spt.x + Ssize.x;
		else if(p.x < Spt.x - Ssize.x)
			p.x = Spt.x - Ssize.x;
	
		if(p.y > Spt.y + Ssize.y)
			p.y = Spt.y + Ssize.y;
		else if(p.y < Spt.y - Ssize.y)
			p.y = Spt.y - Ssize.y;

		return CheckCollision(cir,p);
	}
}
float CollisionManager::CheckCollision(const Square &sqr1, const Square &sqr2)
{
	Vector2 Pt = sqr1.GetPosition();
	if(sqr1.GetTextureAngle() || sqr2.GetTextureAngle())
	{
		
		Vector2 dist = Pt - sqr2.GetPosition();
		Vector2 HalfSize[2];
		//Ball1
		HalfSize[0] = sqr1.GetSize()/2;
		//Ball2
		HalfSize[1] = sqr2.GetSize()/2;
		float sum = 0;
		for(unsigned int i = 0; i < 2 ;++i)
		{
			float d1 = std::abs(dist.Dot(sqr2.GetAxis(i)));
			float d2 = std::abs(dist.Dot(sqr1.GetAxis(i)));
			float C1 = sqr1.CollisionProject(HalfSize[0],sqr2.GetAxis(i)) + sqr2.CollisionProject(HalfSize[1],sqr2.GetAxis(i));
			float C2 = sqr1.CollisionProject(HalfSize[0],sqr1.GetAxis(i)) + sqr2.CollisionProject(HalfSize[1],sqr1.GetAxis(i));
			
			if(d1 > C1)
				return 0;
			if(d2 > C2)
				return 0;
			sum += (C1 - d1) + (C2 - d2);

		}
		return  sum/4;
	}
	else
	{
	//max 1 < min2
	Vector2 pos2 = sqr2.GetPosition();
	Vector2 size1 = sqr1.GetSize()/2;
	Vector2 size2 = sqr2.GetSize()/2;
		if(Pt.x + (size1.x) < pos2.x - (size2.x))
			return 0;
		if(Pt.x - (size1.x) > pos2.x + (size2.x))
			return 0;
		if(Pt.y + (size1.y) < pos2.y - (size2.y))
			return 0;
		if(Pt.y - (size1.y) > pos2.y + (size2.y))
			return 0;
	}

	return 1;
}
float CollisionManager::CheckCollision(const Square &sqr, const Circle &cir)
{
	return CheckCollision(cir,sqr);
}
float CollisionManager::CheckCollision(const Square &sqr, const Vector2 &vect)
{
	Vector2 size = sqr.GetSize()/2;
	Vector2 Pt = sqr.GetPosition();
	if(Pt.x + (size.x) < vect.x)
		return 0.0;
	if(Pt.x - (size.x) > vect.x)
		return 0.0;
	if(Pt.y + (size.y) < vect.y)
		return 0.0;
	if(Pt.y - (size.y) > vect.y)
		return 0.0;
	CMName::CollisionPoint = vect;
	return 1;
}


float CollisionManager::CaculateImpulse(float Elasticity,float Mass1,float Mass2, float ClosingVel)
{
	return (-(1 + Elasticity) * ClosingVel)/ ((1/Mass1) + (1/Mass2));
}
float CollisionManager::CaculateAngularImpulse(float Elasticity, float Mass1, float Mass2, float ClosingVel, float I1, float I2)
{
	return( -(1 + Elasticity)*ClosingVel)/((1/Mass1) + (1/Mass2) +std::pow(I1,2) + std::pow(I2,2));
}
float CollisionManager::FindSquareRadius(const Vector2 &size)
{
	return std::sqrt(std::pow(size.x/2,2) + std::pow(size.y/2,2));
}
void CollisionManager::ResolveCollision(Sprite &spr1, Sprite &spr2, float penatration)
{

}
void CollisionManager::ResolveCollision(Circle &cir1, Circle &cir2, float penatration)
{
	float Impulse1, Impulse2, ClosingVel, Mass1, Mass2, V1,V2;
	Vector2 Norm, Vel1, Vel2;
	Impulse1 = 0.0f;
	Impulse2 = 0.0f;
	Mass1 = cir1.GetMass();
	Mass2 = cir2.GetMass();
	Vel1 = cir1.GetVel();
	Vel2 = cir2.GetVel();
	Norm = cir1.GetPosition() - cir2.GetPosition();
	//Make sure they are not directly ontop of each other
	if(Norm.x != 0 || Norm.y !=0)
	{
		Norm.normalize();
		ClosingVel = (Vel1 - Vel2).Dot(Norm);
		Impulse1 = CaculateImpulse(cir1.GetElasticity(),Mass1,Mass2,ClosingVel);
		Impulse2 = CaculateImpulse(cir2.GetElasticity(),Mass1,Mass2,ClosingVel);
	}
	else
	{
		Norm.x = 1;
		Norm.y = 1;
		Norm.normalize();
	}
	V1 = (float)Vel1.Magnitude();
	V2 = (float)Vel2.Magnitude();
	//if 1 of the objects are moving
	if(V1 || V2)
	{
		cir1.SetPosition(cir1.GetPosition() + ((V2/(V1+V2) * penatration) * Norm));
		cir2.SetPosition(cir2.GetPosition() - ((V1/(V1+V2) * penatration) * Norm));
	}
	else
	{
		cir1.SetPosition(cir1.GetPosition() + ((Mass2/(Mass1+Mass2) * penatration) * Norm));
		cir2.SetPosition(cir1.GetPosition() - ((Mass1/(Mass1+Mass2) * penatration) * Norm));
	}
	cir1.SetVel(Vel1 + ((Impulse1/Mass1) * Norm));
	cir2.SetVel(Vel2 - ((Impulse2/Mass2) * Norm));
}
void CollisionManager::ResolveCollision(Circle &cir1, Square &sqr, float penatration)
{
	float Mass1,Mass2, ClosingVel, Impulse1, Impulse2,V1,V2;
	Impulse1 = 0.0f;
	Impulse2 = 0.0f;
	Mass1 = cir1.GetMass();
	Mass2 = sqr.GetMass();
	Vector2 Norm, Vel1,Vel2,Pos1,Pos2;
	Vel1 = cir1.GetVel();
	Vel2 = sqr.GetVel();
	Norm = cir1.GetPosition() - CMName::CollisionPoint;
	//Box moves with no angular rotation
	if(sqr.GetCollisionType() == sqr.DYNAMIC_LINEAR)
	{
		if(Norm.x != 0 || Norm.y !=0)
		{
			Norm.normalize();
			ClosingVel = (Vel1 - Vel2).Dot(Norm);
			Impulse1 = CaculateImpulse(cir1.GetElasticity(),Mass1,Mass2,ClosingVel);
			Impulse2 = CaculateImpulse(sqr.GetElasticity(),Mass1,Mass2,ClosingVel);
		}
		else
		{
			Norm.x = 1;
			Norm.y = 1;
			Norm.normalize();
		}
		V1 = (float)Vel1.Magnitude();
		V2 = (float)Vel2.Magnitude();
		//if 1 of the objects are moving
		if(V1 || V2)
		{
			cir1.SetPosition(cir1.GetPosition() + ((V1/(V1+V2) * penatration) * Norm));
			sqr.SetPosition(sqr.GetPosition() - ((V2/(V1+V2) * penatration) * Norm));
		}
		else
		{
			cir1.SetPosition(cir1.GetPosition() + ((Mass2/(Mass1+Mass2) * penatration) * Norm));
			sqr.SetPosition(sqr.GetPosition() - ((Mass1/(Mass1+Mass2) * penatration) * Norm));
		}
		cir1.SetVel(Vel1 + ((Impulse1/Mass1) * Norm));
		sqr.SetVel(Vel2 - ((Impulse2/Mass2) * Norm));
		sqr.SetGravity(Vector2D(0.0f,-.1f));
	}
	//box moves and rotates
	else if(sqr.GetCollisionType() == sqr.DYNAMIC_ANGULAR)
	{
		Vector2 rq1 = CMName::CollisionPoint - cir1.GetPosition();
		Vector2 rq2 = CMName::CollisionPoint - sqr.GetPosition();
		rq1.normalize();
		rq2.normalize();
		if(Norm.x != 0 || Norm.y !=0)
		{
			Norm.normalize();
			Vel1 = rq1.PerpDot(cir1.GetAngVel()) + Vel1;
			Vel2 = rq2.PerpDot(sqr.GetAngVel()) + Vel2;
			ClosingVel = (Vel1 - Vel2).Dot(Norm);
			float I1 = rq1.PerpDot(Norm)/(Mass1* std::pow((float)cir1.GetRadius(),2)/4);
			float I2 = rq2.PerpDot(Norm)/(Mass2 * CollisionManager::FindSquareRadius(sqr.GetSize()));
			//Impulse1 = CaculateImpulse(cir1.GetElasticity(),Mass1,Mass2,ClosingVel);
			//Impulse2 = CaculateImpulse(sqr.GetElasticity(),Mass1,Mass2,ClosingVel);
			Impulse1 = CaculateAngularImpulse(cir1.GetElasticity(),Mass1,Mass2,ClosingVel,I1,I2);
			Impulse2 = CaculateAngularImpulse(sqr.GetElasticity(),Mass1,Mass2,ClosingVel,I1,I2);
		}
		else
		{
			Norm.x = 1;
			Norm.y = 1;
			Norm.normalize();
		}
		V1 = (float)Vel1.Magnitude();
		V2 = (float)Vel2.Magnitude();
		//if 1 of the objects are moving
		if(V1 || V2)
		{
			cir1.SetPosition(cir1.GetPosition() + ((V1/(V1+V2) * penatration) * Norm));
			sqr.SetPosition(sqr.GetPosition() - ((V2/(V1+V2) * penatration) * Norm));
		}
		else
		{
			//cir1.SetPosition(cir1.GetPosition() + ((Mass2/(Mass1+Mass2) * penatration) * Norm));
			//sqr.SetPosition(sqr.GetPosition() - ((Mass1/(Mass1+Mass2) * penatration) * Norm));
		}
		cir1.SetVel(Vel1 + ((Impulse1/Mass1) * Norm));
		//cir1.SetAngVel(cir1.GetAngVel() + rq1.PerpDot(Impulse1 * Norm));
		sqr.SetVel(Vel2 - ((Impulse2/Mass2) * Norm));
		sqr.SetAngVel(sqr.GetAngVel() - rq2.PerpDot(Impulse2/Mass2 * Norm));
		sqr.SetGravity(Vector2D(0.0f,-.1f));
	}
	//box does not rotate or move.
	else if(sqr.GetCollisionType() == sqr.STATIC)
	{
		if(Norm.x != 0 || Norm.y !=0)
		{
			Norm.normalize();
			ClosingVel = (Vel1 - Vel2).Dot(Norm);
			Impulse1 = CaculateImpulse(cir1.GetElasticity(),Mass1,Mass2,ClosingVel);
		}
		else
		{
			Norm.x = 1;
			Norm.y = 1;
			Norm.normalize();
		}
		cir1.SetPosition(cir1.GetPosition() + (penatration * Norm));
		cir1.SetVel(Vel1 + ((Impulse1/Mass1) * (Norm*2)));
	}
	//Box does not move but does rotate.
	else if(sqr.GetCollisionType() == sqr.STATIC_ANGULAR)
	{
		Vector2 rq1 = CMName::CollisionPoint - cir1.GetPosition();
		Vector2 rq2 = CMName::CollisionPoint - sqr.GetPosition();
		rq1.normalize();
		rq2.normalize();
		if(Norm.x != 0 || Norm.y !=0)
		{
			Norm.normalize();
			Vel1 = rq1.PerpDot(cir1.GetAngVel()) + Vel1;
			Vel2 = rq2.PerpDot(sqr.GetAngVel()) + Vel2;
			ClosingVel = (Vel1 - Vel2).Dot(Norm);
			float I1 = rq1.Dot(Norm)/(Mass1* std::pow((float)cir1.GetRadius(),2)/4);
			float I2 = rq2.Dot(Norm)/(Mass2 * CollisionManager::FindSquareRadius(sqr.GetSize()));
			Impulse1 = CaculateAngularImpulse(cir1.GetElasticity(),Mass1,Mass2,ClosingVel,I1,I2);
			Impulse2 = CaculateAngularImpulse(sqr.GetElasticity(),Mass1,Mass2,ClosingVel,I1,I2);
			//Impulse1 = CaculateImpulse(cir1.GetElasticity(),Mass1,Mass2,ClosingVel);
			//Impulse2 = CaculateImpulse(sqr.GetElasticity(),Mass1,Mass2,ClosingVel);
		}
		else
		{
			Norm.x = 1;
			Norm.y = 1;
			Norm.normalize();
		}

		cir1.SetPosition(cir1.GetPosition() + (penatration * Norm));

		cir1.SetVel(Vel1 + ((Impulse1/Mass1) * Norm));
		//cir1.SetAngVel(cir1.GetAngVel() + rq1.PerpDot(Impulse1 * Norm));
		//sqr.SetVel(Vel2 - ((Impulse2/Mass2) * Norm));
		sqr.SetAngVel(sqr.GetAngVel() - rq2.PerpDot(Impulse2/Mass2 * Norm));
	}
}
void CollisionManager::ResolveCollision(Square &sqr, Circle &cir, float penatration)
{
	CollisionManager::ResolveCollision(cir,sqr,penatration);
}
void CollisionManager::ResolveCollision(Square &sqr1, Square &sqr2, float penatration)
{
}