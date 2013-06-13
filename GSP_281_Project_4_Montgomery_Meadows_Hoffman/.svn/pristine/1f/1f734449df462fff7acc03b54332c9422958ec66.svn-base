#ifndef SPRITE_H
#define SPRITE_H

#include "Vector2.h"
#include "Matrix3.h"
#include "Functions.h"
#include <Windows.h>
#include "GraphicsFramework.h"
#include "Line.h"
#include <vector>

class Sprite
{
public:
	enum TYPE{NOCOLLISION,STATIC,DYNAMIC_LINEAR,DYNAMIC_ANGULAR,STATIC_ANGULAR};
	Sprite(float angle);
	Sprite(float angle,float textangle,Vector2 scale, Vector2 Orgion);
	Sprite(float angle,float textangle,Vector2 scale);
	Sprite(float angle,float textangle,Vector2 scale, Vector2 Orgion, Vector2 Trans);
	~Sprite(){};
	bool UpdateCollision(std::vector<Sprite*> &sprt);
	virtual float CheckCollision(const class Circle &cir)const = 0;
	virtual float CheckCollision(const class Square &sqr)const = 0;
	virtual float CheckCollision(const Vector2 &vect)const = 0;
	virtual float CheckCollision(const Sprite &spr)const = 0;
	virtual float GetCollisionPen(const class Circle &cir) const = 0;
	virtual float GetCollisionPen(const class Square &sqr)const = 0;
	virtual void ResolveCollision(class Circle &cir, float pen)=0;
	virtual void ResolveCollision(class Square &sqr,float pen)=0;
	virtual void ResolveCollision(Sprite &spr, float pen) = 0;
	void SetColor(COLORREF color){this->color = color;}
	virtual void Update(float dt) = 0;
	virtual int Get(void) = 0;
	virtual void UpdateScreenCollision(int,int,int,int) = 0;
	virtual void Render(void) = 0;
	bool GetCollisionFlag(void) {return collision;}
	void SetCollisionFlag(bool t) {collision = t;}
	Vector2 GetPosition(void) const {return Pt;}
	Vector2 GetVel(void)const{return vel;}
	float GetMass(void)const{return Mass;}
	float GetTextureAngle(void)const{return TextureAngle;}
	void SetPosition(const Vector2 &vect);
	void SetOrgion(const Vector2 &vect){Orgion = vect;}
	void SetVel(const Vector2 &vect){vel = vect;}
	float GetElasticity(void){return elasticity;}
	void ChangeTextureAngle(float f){TextureAngle = f;};
	Vector2 PointMath(const Vector2 &pt1)const;
	Vector2 GetScale(void){return Scale;};
	float CollisionProject(const Vector2 &size, const Vector2 &vect)const;
	void UpdateAxis(void);
	float GetAngVel(void)const{return AngVel;}
	void SetAngVel(float f){AngVel =f;}
	Vector2 GetAxis(int i) const{return M_Axis[i];}
	TYPE GetCollisionType(void)const{return CollisionType;}
	void SetGravity(Vector2 g) {Gravity = g;}
protected:
	//Position of the sprite
	Vector2 Pt;
	//Velicity of the sprite
	Vector2 vel;
	//Angular Velocity
	float AngVel;
	//The scale Vector of the sprite
	Vector2 Scale;
	//The Orgion of where to draw the sprite
	Vector2 Orgion;
	//The Transpose
	Vector2 Transpose;
	//The TextureAngle of the sprite
	float TextureAngle;
	//The Axis;
	Vector2 M_Axis[2];
	//The color
	COLORREF color;
	//If they have collided
	bool collision;
	//Vel angle
	float angle;
	//Mass
	float Mass;
	//Elasticity
	float elasticity;
	//Texture
	HBITMAP *texture;
	//The handle to the brush
	HBRUSH hBrush;
	//tells us if this guy is a square circle or some other thing.
	int t;
	//No collision, Rotational Collision, NoRotationCollision
	TYPE CollisionType;
	//The Y acceleration
	Vector2 Gravity;
};
class Circle : public Sprite
{
public:
	Circle(Vector2 pt1, Vector2 pt2, COLORREF color);
	Circle(Vector2 pt1, float radius, COLORREF color);
	Circle(Vector2 pos, float radius,float mass, float vel, float angle, COLORREF color);
	//Circle(Vector2 pos, COLORREF color, int radius = 10,float scale=1.0f, int vel = 1, float angle = 0.0f,float mass = 1, float elasticity = .9);
	Circle(Vector2 pos, COLORREF color, HBITMAP *texture, float radius = 10.0f,float scale=1.0f, float vel = 0, float angle = 0.0f,float mass = 1, float elasticity = .9);
	~Circle();

	void SetRadius(Vector2 const &pt);
	void Render(void);
	int Get(void){return t;}
	float GetRadius(void) const {return this->radius;}
	Vector2 GetPosition(void) const {return this->Pt;}
	float CheckCollision(const Circle &cir) const;
	float CheckCollision(const class Square &sqr) const;
	float CheckCollision(const Vector2 &vect) const;
	float CheckCollision(const Sprite &spr) const;
	void ResolveCollision(class Circle &cir, float pen);
	void ResolveCollision(class Square &sqr, float pen);
	void ResolveCollision(Sprite &spr,float pen);
	float GetCollisionPen(const Circle &cir) const;
	float GetCollisionPen(const class Square &sqr) const;
	virtual void UpdateScreenCollision(int minx, int MaxX, int miny,int maxy);
	void ResolveScreenCollision(void);
	virtual void Update(float dt);
protected:
	float radius;

};
class Square : public Sprite
{
public:
	Square(Vector2 pos,float size,float mass,float vel,float angle, COLORREF color, float E = .8f);
	Square(Vector2 pos,float size,float vel,float angle,float textureangle, Vector2 &scale,Vector2 &Orgion, COLORREF color, float E = .8f);
	Square(Vector2 pos,const Vector2 &size,float vel,float angle,float textureangle,float mass, Vector2 &scale,Vector2 &Orgion, COLORREF color,float E = .8f, TYPE t = DYNAMIC_LINEAR);
	~Square();
	void Render(void);
	virtual void Update(float dt);
	void SetSize(float x,float y);
	int Get(void){return t;}
	const Vector2 GetSize(void) const {return this->size;}
	Vector2 GetPosition(void) const {return this->Pt;}
	float CheckCollision(const Circle &cir) const;
	float CheckCollision(const Square &sqr) const;
	float CheckCollision(const Vector2 &vect) const;
	float CheckCollision(const Sprite &spr) const;
	void ResolveCollision(class Circle &cir,float pen);
	void ResolveCollision(class Square &sqr,float pen);
	void ResolveCollision(Sprite &spr,float pen);
	float GetCollisionPen(const Square &sqr) const;
	float GetCollisionPen(const Circle &cir) const;
	virtual void UpdateScreenCollision(int minx, int MaxX, int miny,int maxy);
protected:
	Vector2 size;
};
#endif