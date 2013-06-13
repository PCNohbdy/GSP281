#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
#include "Sprite.h"
#include "CollisionManager.h"
#include <map>
#include "Particle.h"
#include "Firework.h"
#include "BaseEntity.h"
#include "Ball.h"
#include <string>
#define PI = 3.1415927
#define OM ObjectManager::Instance()
class ObjectManager
{
public:
	~ObjectManager();
	static ObjectManager* Instance();
	void CMInit(RECT rect){CM.Init(rect);}
	void Update(float time);
	void Draw(void)const;
	void Clear(void);
	void Init(void);
	void LoadTextures(void);
		void CreateObject(Sprite *sprt);
		void DeleteObject(Sprite *sprt);
		Square* CreateSquare(Vector2 &pos, Vector2 &size, float mass, COLORREF color = RGB(0,255,0));
		Circle* CreateBall(Vector2 &pos, float size, float mass,COLORREF color = RGB(0,255,0));
	void AddSquareParticles(int amount,const Vector2 &Pos,COLORREF color);
	void AddCircleParticles(int amount,const Vector2 &Pos,COLORREF color);
	std::vector<Sprite*>& GetObjectVector(void){return Objects_2D;}
private:
	ObjectManager();
	CollisionManager CM;
	std::vector<Sprite*> Objects_2D;
	std::vector<Sprite*> Particles_2D;
	//std::vector<BaseEntity*> Objects_3D;
	//std::vector<BaseEntity*> Particles_3D;
	//The map that holds the Textures.
	HBITMAP TextureMap;
};
#endif