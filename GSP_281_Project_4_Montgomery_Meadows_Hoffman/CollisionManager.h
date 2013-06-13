#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include "Sprite.h"
//#include "BaseEntity.h"
//#include "Vector3.h"

class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();
	void Init(RECT rect);
	RECT Screen;
	//Checks Collisions and Updates Collisions
	void Update(std::vector<Sprite*> &sprite);
	//void Update(std::vector<BaseEntity*> &Base);
	static float CaculateImpulse(float,float,float,float);
	static float CaculateAngularImpulse(float,float,float,float,float,float);
	static float FindSquareRadius(const Vector2 &vect);
	static void ResolveCollision(Circle &cir1, Circle &cir2, float penatration);
	static void ResolveCollision(Square &sqr1, Square &sqr2, float penatration);
	static void ResolveCollision(Circle &cir1, Square &sqr, float penatration);
	static void ResolveCollision(Square &sqr, Circle &cir, float penatration);
	static void ResolveCollision(Sprite &spr1, Sprite &spr2, float penatration);
	static float CheckCollision(const Circle &cir1, const Circle &cir2);
	static float CheckCollision(const Circle &cir, const Square &sqr);
	static float CheckCollision(const Square &sqr1, const Square &sqr2);
	static float CheckCollision(const Square &sqr, const Circle &cir);
	static float CheckCollision(const Square &sqr, const Vector2 &vect);
	static float CheckCollision(const Circle &cir, const Vector2 &vect);
	static float CheckCollision(const Sprite &spr1, const Sprite &spr2);
	static void ToggleDebug();
	static bool GetDebug();
private:
	
};






#endif