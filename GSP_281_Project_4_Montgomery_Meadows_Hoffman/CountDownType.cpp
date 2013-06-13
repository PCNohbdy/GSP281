#include "GameLogic.h"


CountDownType::CountDownType(float time, GameLogic::TYPE t)
{
	this->time = time;
	this->type = t;
}
CountDownType::~CountDownType(void)
{

}
void CountDownType::Update(float dt)
{
	time -= dt;
}