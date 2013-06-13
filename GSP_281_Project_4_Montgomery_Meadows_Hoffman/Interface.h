#ifndef INTERFACE_H
#define INTERFACE_H
#include "BaseAIEntity.h"
#include <vector>
#include <list>
#include <queue>
#include "Food.h"
#define AM AIManager::Instance()
#define MS MessagingSystem::Instance()
#define SM SystemManager::Instance()
//The Enum Starting State
//enum STATETYPE {WANDER,SEEK,FLEE,ATTACK};
//The Enum If you want to specify the enum type you must use EntityManager::TYPE::<insert type here>;
enum ENTITYTYPE {COOKS,HOSTS,WAITERS};

class Machine;
struct MessageStruct
{
public:
	//float t = the delayed time in miliseconds
	MessageStruct(const STATETYPE Msg,const int S_ID,const int R_ID,double t, VOID* = NULL);
	~MessageStruct(){};
	const int Sender_ID, Reciever_ID;
	const STATETYPE Message;
	double time;
	VOID* M_VPtr;
	//Not needed due to constructor.
	//MessageStruct* CreateMessage(const STATETYPE Msg,const int S_ID,const int R_ID, float time){return new MessageStruct(Msg,S_ID,R_ID,time);};
};
//This is used for the priority queue as the compare function.
class Compare
{
public:
	bool operator()(const MessageStruct *rhs,const MessageStruct *lhs)
	{
		return rhs->time > lhs->time;
	}
};

class MessagingSystem
{
public:
	//Singelton
	static MessagingSystem* Instance();
	//Gets the Next AvailableMessage this also pops off the message from the queue this does not delete the message!
	//Delete the Message after you are done with it or you will have a memory leak!
	MessageStruct* GetNextMessage(void);
	//Does Not Care about time;
	MessageStruct* GetNextMessageNow(void);
	//Sends a delayed message STATETYPE is the message S_ID = sender, R_ID = reciever
	void SendDelayedMessage(const STATETYPE Msg, const int S_ID,const int R_ID,float DelayedTime);
	//Sends a message with no delay
	void SendMessageNow(const STATETYPE Msg, const int S_ID,const int R_ID);
	//The update message
	void Update(float dt);
	//Get Clock
	double GetClock(void){return clock;};
	//Resets the Clock
	void   ResetClock(void){clock = 0.0f;};
	//Clears out the messaging system
	void Clear(void);
	//Destructor
	~MessagingSystem();
private:
	MessagingSystem(){clock = 0.0f;}
	//This clock is the total time that has passed while the game is running. Just like the timer clock in the game that is being printed.
	double clock;
	//The priority_queue for the messaging system
	//you can only look at the first element in the queue in order to access the other you have to pop off the first element
	std::priority_queue<MessageStruct*,std::vector<MessageStruct*>,Compare> MessageQueue;
};



//Use this class to update your AIManager SystemManager and World/Object Manager
class SystemManager
{
public:
	//This is the singleton
	static SystemManager* Instance();
	//Update for all the systems
	void Update(float dt);
	//Destructor
	~SystemManager();
private:
	//Constructor
	SystemManager(){};
};

class AIManager
{
public:
	//Singelton
	static AIManager* Instance();
	//Destructor
	~AIManager();
	//Create Entity
	int CreateEntity(float PosX, float PosY, ENTITYTYPE Et, STATETYPE t = WORKING);
	//Delete Entity
	bool DeleteEntity(int id);
	//Clears out all AI Entities
	void Clear(void);
	//Change Entity State
	bool ChangeEntityState(int id, STATETYPE t);
	//Update function dt = time elapsed per frame .016 = 60fps .033 = 30fps
	void Update(float dt);
	//Returns the BaseAIEntity with the given ID
	BaseAIEntity* GetBaseAIEntity(const int id);
	//Deletes the machine off the vector
	//void AddMachine(Machine *m);
	//Get one
	//Machine* GetBrokenMachine();
	//Get NumberOfMachinesInQueue
	// long double GetMachineNumberQueue(void){return NumberOfTimesAMachinesWasAdded;}
	//inline long double GetTotalMachineBroken(void){return NumberOfBrokenMachinesInQueue;}
	//void ResetData(void);
		//Complete
	//void Complete(void);
private:
	//Constructor
	AIManager(){NextID = 0;}
	//Next AI unique id
	int NextID;
	//The vector of Entityies the AI system holds
	std::vector<BaseAIEntity*> AIEntities;
	//Broken Queue
	//long double NumberOfBrokenMachinesInQueue;
	//long double NumberOfTimesAMachinesWasAdded;
};






#endif