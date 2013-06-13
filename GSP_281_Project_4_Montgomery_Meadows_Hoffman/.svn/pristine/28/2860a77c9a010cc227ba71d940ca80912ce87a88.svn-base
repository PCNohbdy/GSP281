#ifndef COOKS_H
#define COOKS_H
#include "BaseAIEntity.h"
#include "StateMachine.h"
#include "GlobalData.h"
#include "Interface.h"
#include "Payment.h"
#include "Food.h"
class Cooks : public BaseAIEntity
{
public:
	float StartTime;
	float EndTime;
	Payment *P;
	StateMachine<Cooks>* m_pStateMachine;
	std::vector<Food*> m_FoodBeingCooked;
	Cooks(Vector2 pos, float mass, float radius, const int id, STATETYPE t):BaseAIEntity(id)
	{	
		StartTime = 0.0f;
		EndTime = 0.0f;
		m_pStateMachine = new StateMachine<Cooks>(this);
		if(t == WORKING)
			m_pStateMachine->SetCurrentState(Working::Instance());
		else if(t == WAITING)
			m_pStateMachine->SetCurrentState(Waiting::Instance());
		else if(t == CLEANING)
			m_pStateMachine->SetCurrentState(Cleaning::Instance());
		else if(t == SERVING)
			m_pStateMachine->SetCurrentState(Serving::Instance());
		else if(t == PAYING)
			m_pStateMachine->SetCurrentState(Paying::Instance());
		else if(t == ORDERING)
			m_pStateMachine->SetCurrentState(Ordering::Instance());
		else
			m_pStateMachine->SetCurrentState(Working::Instance());
	}
	virtual void Update(float dt)
	{
		m_pStateMachine->Update(dt);
	}
	inline StateMachine<Cooks>* GetFSM(void)const{return m_pStateMachine;}
	virtual void ChangeState(STATETYPE t)
	{
		if(t == WORKING)
			m_pStateMachine->ChangeState(Working::Instance());
		else if(t == WAITING)
			m_pStateMachine->ChangeState(Waiting::Instance());
		else if(t == CLEANING)
			m_pStateMachine->ChangeState(Cleaning::Instance());
		else if(t == SERVING)
			m_pStateMachine->ChangeState(Serving::Instance());
		else if(t == PAYING)
			m_pStateMachine->ChangeState(Paying::Instance());
		else if(t == ORDERING)
			m_pStateMachine->ChangeState(Ordering::Instance());
	}
	virtual void OnMessage(MessageStruct &msg)
	{
		
		if(msg.Message == COOKED)
		{
			((Food*)msg.M_VPtr)->SetState(Food::STATE::COOKED);
		}
		else
			ChangeState(msg.Message);
	}
};


#endif