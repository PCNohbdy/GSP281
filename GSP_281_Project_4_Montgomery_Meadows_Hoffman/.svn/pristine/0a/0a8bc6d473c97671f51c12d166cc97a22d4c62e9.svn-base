#include "Interface.h"



MessageStruct::MessageStruct(const STATETYPE Msg,const int S_ID,const int R_ID,double t, VOID* ptr):Message(Msg),Sender_ID(S_ID),Reciever_ID(R_ID)
{
	time = MS->GetClock() + t; 
	M_VPtr = ptr;
};