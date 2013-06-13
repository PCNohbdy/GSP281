#ifndef STATEMACHINE_H
#define STATEMACHINE_H


#include "Working.h"
#include "Waiting.h"
#include "Cleaning.h"
#include "Serving.h"
#include "Paying.h"
#include "Ordering.h"
template<class T>
class StateMachine
{
private:
	T*	m_pOwner;
	State*	m_pCurrentState;
	State*  m_pPreviousState;
	State*  m_pGlobalState;
public:
	StateMachine(T *owner):m_pOwner(owner),m_pCurrentState(NULL),m_pPreviousState(NULL),m_pGlobalState(NULL){};
	void SetCurrentState(State *state)
	{
		m_pCurrentState = state;
		m_pPreviousState = state;
		m_pGlobalState = NULL;
	}
	void Update(float dt)
	{
		if(m_pGlobalState) m_pGlobalState->Execute(m_pOwner,dt);
		if(m_pCurrentState) m_pCurrentState->Execute(m_pOwner,dt);
	}
	void ChangeState(State *pNewState)
	{
		m_pPreviousState = m_pCurrentState;
		if(m_pCurrentState)
			m_pCurrentState->Exit(m_pOwner);
		
		m_pCurrentState = pNewState;
		
		if(m_pCurrentState)
			m_pCurrentState->Enter(m_pOwner);
	}
	void RevertToPreviousState()
	{
		ChangeState(m_pPreviousState);
	}
};




#endif