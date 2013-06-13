#include "Interface.h"
#include "Waiters.h"
#include "Cooks.h"
#include "Hosts.h"
#include "ObjectManager.h"
#include "BusBoy.h"
AIManager* AIManager::Instance()
{
	static AIManager* AIMan = new AIManager();
	return AIMan;
}
AIManager::~AIManager()
{
	for(unsigned int i = 0; i < AIEntities.size();)
	{
		delete AIEntities[i];
		AIEntities.erase(AIEntities.begin());
	}
}
int AIManager::CreateEntity(float x, float y, ENTITYTYPE et, STATETYPE st)
{
	int TempID = NextID;
	if(et == ENTITYTYPE::COOKS)
	{
		Cooks *def = new Cooks(Vector2D(x,y),10,1,NextID++,st);
		def->base = OM->CreateSquare(Vector2D(x,y),Vector2D(10,1),1);
		AIEntities.push_back(def);
		MS->SendMessageNow(st,def->m_id,def->m_id);
	}
	else if(et == ENTITYTYPE::WAITERS)
	{
		Waiters *Meme = new Waiters(Vector2D(x,y),10,1,NextID++,st);
		Meme->base = OM->CreateBall(Vector2D(x,y),5,5);
		AIEntities.push_back(Meme);
		MS->SendMessageNow(st,Meme->m_id,Meme->m_id);
	}

	else if(et == ENTITYTYPE::HOSTS)
	{
		Hosts *Meme = new Hosts(Vector2D(x,y),10,1,NextID++,st);
		Meme->base = OM->CreateBall(Vector2D(x,y),5,5);
		AIEntities.push_back(Meme);
		MS->SendMessageNow(st,Meme->m_id,Meme->m_id);
	}
	else
	{
		BusBoy *Meme = new BusBoy(Vector2D(x,y),10,1,NextID++,st);
		Meme->base = OM->CreateBall(Vector2D(x,y),5,5);
		AIEntities.push_back(Meme);
		MS->SendMessageNow(st,Meme->m_id,Meme->m_id);
	}
	return TempID;
}
BaseAIEntity* AIManager::GetBaseAIEntity(const int id)
{
	for(unsigned int i = 0; i < AIEntities.size();++i)
	{
		if(AIEntities[i]->m_id == id)
		{
			return AIEntities[i];
		}
	}
	return NULL;
}
bool AIManager::DeleteEntity(int id)
{
	for(unsigned int i = 0; i < AIEntities.size();++i)
	{
		if(AIEntities[i]->m_id == id)
		{
			delete AIEntities[i];
			AIEntities.erase(AIEntities.begin()+i);
			return true;
		}
	}
	return false;
}
void AIManager::Clear(void)
{
	MS->Clear();
	for(unsigned int i = 0; i < AIEntities.size();)
	{
		delete AIEntities[i];
		AIEntities.erase(AIEntities.begin()+i);
	}
}
bool AIManager::ChangeEntityState(const int id, STATETYPE st)
{
	for(unsigned int i = 0; i < AIEntities.size();++i)
	{
		if(AIEntities[i]->m_id == id)
		{
			AIEntities[i]->ChangeState(st);
			return true;
		}
	}
	return false;
}
void AIManager::Update(float dt)
{
	for(unsigned int i = 0; i < AIEntities.size();++i)
	{
		AIEntities[i]->Update(dt);
	}
}



//void AIManager::ResetData(void)
//{
//	NumberOfTimesAMachinesWasAdded = 0;NumberOfBrokenMachinesInQueue = 0;
//	for(unsigned int i = 0; i < AIEntities.size();++i)
//	{
//		MS->SendMessageNow(RESET,AIEntities[i]->m_id,AIEntities[i]->m_id);
//	}
//}