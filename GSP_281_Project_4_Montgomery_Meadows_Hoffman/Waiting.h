#ifndef WAITING_H
#define WAITING_H
#include "State.h"


class Waiting:public State
{
private:
	Waiting():State(){}
public:
	static Waiting* Instance(){	static Waiting *ptr = new Waiting(); return ptr;};
	virtual void Enter(Cooks *m);
	virtual void Execute(Cooks *m, float dt);
	virtual void Exit(Cooks *m);
	virtual void Enter(Hosts *def);
	virtual void Execute(Hosts *def, float dt);
	virtual void Exit(Hosts *def);
	virtual void Enter(Waiters *def);
	virtual void Execute(Waiters *def, float dt);
	virtual void Exit(Waiters *def);
	virtual void Enter(BusBoy *def);
	virtual void Execute(BusBoy *def, float dt);
	virtual void Exit(BusBoy *def);
	//virtual bool OnMessage(Defense *def, const Telegram& msg);
};
#endif