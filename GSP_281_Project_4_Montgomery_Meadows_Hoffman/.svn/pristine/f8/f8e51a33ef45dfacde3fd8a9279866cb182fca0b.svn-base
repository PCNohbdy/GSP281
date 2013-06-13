#ifndef LINE_H
#define LINE_H

#include <Windows.h>
#include "GraphicsFramework.h"
#include "Functions.h"
#include "Vector2.h"
class Line
{
public:
	Line();
	Line(Vector2 p1,Vector2 p2,COLORREF color);
	void SetPoints(Vector2 p1, Vector2 p2){Pt1 = p1; Pt2 = p2;}
	//void Rotate(float angle);
	void Render();
	Vector2 Pt1,Pt2;
	COLORREF color;
};
#endif