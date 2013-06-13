#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include "CollisionManager.h"
#include "Firework.h"
#include "Spawner.h"
class GameLogic 
{
public:
	enum TYPE{SLOW,NORM,FAST,END};
	GameLogic();
	~GameLogic();
	void Init(const int TableSize,const int StoolSize,const int BoothSize,const int CooksSize, const int WaiterSize, const int HostSize, const int Years = 2);
	void Update(float dt);
	void Draw(void);
	void ChangeType(TYPE t);
	void UpdateSpawnerSpeed();
private:
	std::vector<Spawner*> spawners;
	std::vector<class CountDownType*> countdown;
	TYPE type;

};
class CountDownType
{
public:
	CountDownType(float time, GameLogic::TYPE t);
	~CountDownType();
	void Update(float dt);
	float time;
	GameLogic::TYPE type;
};
#endif
