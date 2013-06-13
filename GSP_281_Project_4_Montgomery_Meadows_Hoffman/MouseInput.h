#ifndef MOUSE_INPUT_H
#define MOUSE_INPUT_H
#include "Windows.h"
#include "Vector2.h"
#define MOUSE_LEFT 0x000000001 //0001
#define MOUSE_RIGHT 0x000000002 //0010


class MouseInput
{
public:
	Vector2 coord;
	DWORD ButtonClick;
	MouseInput();
	~MouseInput();

};
extern MouseInput* Minput;

#endif