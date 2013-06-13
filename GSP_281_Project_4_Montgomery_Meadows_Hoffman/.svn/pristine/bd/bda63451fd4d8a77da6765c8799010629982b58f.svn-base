#include "GameLogic.h"
#include "Interface.h"
#include "GlobalData.h"
#include "Planner.h"
GameLogic::GameLogic()
{

}
GameLogic::~GameLogic()
{
	for(unsigned int i = 0; i < spawners.size();)
	{
		delete spawners[i];
		spawners.erase(spawners.begin() + i);
	}
	for(unsigned int i = 0; i < countdown.size();)
	{
		delete countdown[i];
		countdown.erase(countdown.begin() + i);
	}
}
void GameLogic::Init(const int TableSize,const int StoolSize,const int BoothSize,const int CooksSize, const int WaiterSize, const int HostSize, const int Years)
{
	//init messaging system
	//GD->Init(BreakDownTime,FixTime,TechCount,Years*120000);
	PM->SetTables(TableSize);
	int x = 0;
	int y = 0;
	
	for(unsigned int i = 0; i < (unsigned)CooksSize; ++i)
	{
		if(i % 10 == 0)
		{
			x = 0;
			++y;
		}
		else
			++x;
		AM->CreateEntity((float)x * 20 + 30,(float)y * 15, COOKS, WAITING);
	}
	
	x = 0;
	y = 0;
	
	for(unsigned int i = 0; i < (unsigned)WaiterSize; ++i)
	{
		if(i % 10 == 0)
		{
			x = 0;
			++y;
		}
		else
			++x;
		AM->CreateEntity((float)x*20+30,(float)(y*15)+250,WAITERS,WAITING);
	}
	x = 0;
	y = 0;
	
	for(unsigned int i = 0; i < (unsigned)HostSize; ++i)
	{
		if(i % 10 == 0)
		{
			x = 0;
			++y;
		}
		else
			++x;
		AM->CreateEntity((float)x*20+30,(float)(y*15)+250,HOSTS,WAITING);
	}
}
void GameLogic::Update(float dt)
{
	AM->Update(dt);
	MS->Update(dt);
	OM->Update(dt);
}
void GameLogic::Draw(void)
{
	OM->Draw();
}
void GameLogic::ChangeType(GameLogic::TYPE t)
{
	this->type = t;
	UpdateSpawnerSpeed();
}
void GameLogic::UpdateSpawnerSpeed()
{
}