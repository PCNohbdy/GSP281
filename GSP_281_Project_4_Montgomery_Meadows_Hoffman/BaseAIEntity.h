#ifndef BASEAIENTITY
#define BASEAIENTITY
#include "Sprite.h"
enum STATETYPE {WORKING,WAITING,CLEANING,SERVING,PAYING,ORDERING,COOKED,RAW};
struct MessageStruct;

class BaseAIEntity
{
public:
	BaseAIEntity(const int id):m_id(id){base = NULL;};
	~BaseAIEntity(){};
	virtual void Update(float dt) = 0;
	virtual void ChangeState(STATETYPE t) = 0;
	virtual void OnMessage(MessageStruct &msg) = 0;
	const int m_id;
	Sprite* base;
};






#endif