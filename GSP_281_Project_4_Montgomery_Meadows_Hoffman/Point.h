#ifndef POINT_H
#define POINT_H
#include "Vector2.h"

class Point
{
public:
	Point(){};
	Point(int x, int y){this->x = x; this->y = y;};
	int x,y;
};

#endif
