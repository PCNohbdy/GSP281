#include "Interface.h"
#include <stdio.h>
MessageStruct* MessagingSystem::GetNextMessage()
{
	if(MessageQueue.size() > 0)
	{
		if(MessageQueue.top()->time <= this->clock)
		{
			MessageStruct* MSG = MessageQueue.top();
			MessageQueue.pop();
			return MSG;
		}
	}
	return NULL;
}
MessageStruct * MessagingSystem::GetNextMessageNow()
{
	if(MessageQueue.size() > 0)
	{
		MessageStruct* MSG = MessageQueue.top();
		MessageQueue.pop();
		return MSG;
	}
	return NULL;
}
MessagingSystem* MessagingSystem::Instance()
{
	static MessagingSystem* MessSystem = new MessagingSystem();
	return MessSystem;
}
MessagingSystem::~MessagingSystem()
{
	while(MessageQueue.size())
	{
		delete MessageQueue.top();
		MessageQueue.pop();
	}
}
void MessagingSystem::SendMessageNow(const STATETYPE Msg, const int S_ID,const int R_ID)
{
	AM->ChangeEntityState(R_ID,Msg);
}
void MessagingSystem::SendDelayedMessage(const STATETYPE Msg, const int S_ID, const int R_ID, float DelayedTime)
{
	MessageQueue.push(new MessageStruct(Msg,S_ID,R_ID,DelayedTime));
}
void MessagingSystem::Clear(void)
{
	while(MessageQueue.size() > 0)
	{
		MessageStruct* MSG = MessageQueue.top();
		MessageQueue.pop();
		delete MSG;
	}
	clock = 0.0f;
	int temp1 = MessageQueue.size();
}
void MessagingSystem::Update(float dt)
{
	//clock += dt;
	MessageStruct *msg = GetNextMessageNow();
	while(msg != NULL)
	{
		float time = (float)msg->time;
		AM->GetBaseAIEntity(msg->Reciever_ID)->OnMessage(*msg);
		clock = msg->time;
		delete msg;
		msg = GetNextMessage();
		if(msg != NULL)
		{
			if(msg->time != time)
				return;
		}
		else 
			return;
	}
}