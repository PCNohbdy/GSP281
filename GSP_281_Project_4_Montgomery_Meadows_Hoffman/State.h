#ifndef STATE_H
#define STATE_H

class Cooks;
class Hosts;
class Waiters;
class BaseEntity;
class BusBoy;
class State
{
public:
	State(){};
	virtual void Enter(Cooks*)=0;
	virtual void Execute(Cooks*, float dt)=0;
	virtual void Exit(Cooks*)=0;
	virtual void Enter(Waiters*)=0;
	virtual void Execute(Waiters*, float dt)=0;
	virtual void Exit(Waiters*)=0;
	virtual void Enter(Hosts*)=0;
	virtual void Execute(Hosts*, float dt)=0;
	virtual void Exit(Hosts*)=0;
	virtual void Enter(BusBoy *def)=0;
	virtual void Execute(BusBoy *def, float dt)=0;
	virtual void Exit(BusBoy *def)=0;
	virtual ~State(){};
};

#endif