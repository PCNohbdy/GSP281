#include "MouseInput.h"

MouseInput* Minput = NULL;


MouseInput::MouseInput()
{
	this->coord.x = 0.0f;
	this->coord.y = 0.0f;
	this->ButtonClick = 0x000000000;
	Minput = this;
}
MouseInput::~MouseInput()
{
}