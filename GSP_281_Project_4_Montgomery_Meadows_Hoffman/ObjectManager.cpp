#include "ObjectManager.h"
#include "Firework.h"


GraphicsFramework* PGraphics;
ObjectManager::ObjectManager()
{
}
ObjectManager* ObjectManager::Instance()
{
	static ObjectManager *ptr = new ObjectManager();
	return ptr;
}
ObjectManager::~ObjectManager()
{
	for(unsigned int i = 0; i < Particles_2D.size();)
	{
		delete Particles_2D[i];
		Particles_2D.erase(Particles_2D.begin() + i);
	}
	for(unsigned int i = 0; i < Objects_2D.size();)
	{
		delete Objects_2D[i];
		Objects_2D.erase(Objects_2D.begin() + i);
	}
}
void ObjectManager::Clear()
{
	for(unsigned int i = 0; i < Particles_2D.size();)
	{
		delete Particles_2D[i];
		Particles_2D.erase(Particles_2D.begin() + i);
	}
	for(unsigned int i = 0; i < Objects_2D.size();)
	{
		delete Objects_2D[i];
		Objects_2D.erase(Objects_2D.begin() + i);
	}
}
void ObjectManager::Init()
{
	LoadTextures();
	//CM.Init();
}
void ObjectManager::LoadTextures()
{
	TextureMap = (HBITMAP) LoadImage(NULL,"Textures/background.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
}
void ObjectManager::AddSquareParticles(int num,const Vector2 &pos, COLORREF color)
{
	for(int i = 0; i < num; ++i)
	{
		float angle = (float)(rand()%360);
		angle = angle*3.14f/180;
		//Particle is a templatized class that takes a class of a square or circle
		Particles_2D.push_back(new Particle<Square>(pos,20.0f,rand()%3+1.0f,angle,1.0f,color));
	}
}
//Adding Circle Particles_2D
void ObjectManager::AddCircleParticles(int num,const Vector2 &pos, COLORREF color)
{
	for(int i = 0; i < num; ++i)
	{
		float angle = (float)(rand()%360);
		angle = angle*3.14f/180;
		//Particle is a templatized class that takes a class of a square or circle
		Particles_2D.push_back(new Particle<Circle>(pos,10.0f,rand()%3+1.0f,angle,1.0f,color));
	}
}
void ObjectManager::Update(float time)
{
	//CM.Update(Objects_2D);
	for(unsigned int i = 0; i < Particles_2D.size(); ++i)
	{
		Particles_2D[i]->Update(time);
		if(Particles_2D[i]->GetCollisionFlag())
		{
			delete Particles_2D[i];
			Particles_2D.erase(Particles_2D.begin() + i);
			--i;
		}
	}
	for(unsigned int i = 0; i < Objects_2D.size(); ++i)
	{
		Objects_2D[i]->Update(time);
		if(Objects_2D[i]->GetCollisionFlag())
		{
			delete Objects_2D[i];
			Objects_2D.erase(Objects_2D.begin() + i);
			--i;
		}
	}
}
void ObjectManager::Draw()const
{
	//Drawing the BackGround Texture
	PGraphics->LoadBMP(TextureMap);
	for(unsigned int i = 0; i < Objects_2D.size(); ++i)
	{
		Objects_2D[i]->Render();
	}
	for(unsigned int i = 0; i < Particles_2D.size(); ++i)
	{
		Particles_2D[i]->Render();
	}
	//PGraphics->AddText(-200,-100,"Right Click To Toggel Debug Drawing");
	PGraphics->Draw();
}

void ObjectManager::CreateObject(Sprite *sprt)
{
	Objects_2D.push_back(sprt);
}

void ObjectManager::DeleteObject(Sprite *sprt)
{
	for(unsigned int i = 0; i < Objects_2D.size( ); ++i)
	{
		if(Objects_2D[i] == sprt)
		{
			delete Objects_2D[i];
			Objects_2D.erase(Objects_2D.begin()+i);
			break;
		}
	}
}

Circle* ObjectManager::CreateBall(Vector2 &pos, float size, float mass,COLORREF color)
{
	Circle *temp = new Circle(pos, size, mass, 0,0, color);
	Objects_2D.push_back(temp);
	return temp;
}

Square* ObjectManager::CreateSquare(Vector2 &pos, Vector2 &size, float mass, COLORREF color)
{
	Square *temp = new Square(pos, size.x,mass, 0, 0, color);
	Objects_2D.push_back(temp);
	return temp;
}