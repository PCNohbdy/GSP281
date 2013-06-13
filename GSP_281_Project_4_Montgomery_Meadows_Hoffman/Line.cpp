#include "Line.h"
#include "Point.h"
extern GraphicsFramework *PGraphics;
//Constructor
Line::Line()
{
	this->color = RGB(255,255,255);
	Pt1 = Zero();
	Pt2 = Zero();
}
//Destructor
Line::Line(Vector2 p1,Vector2 p2,COLORREF color)
{
	this->color = color;
	Pt1 = p1;
	Pt2 = p2;
}
//Rendering the line
void Line::Render()
{
	Point pt1;
	Point pt2;
	pt1.x = (int)this->Pt1.x;
	pt1.y = (int)this->Pt1.y;
	pt2.x = (int)this->Pt2.x;
	pt2.y = (int)this->Pt2.y;
		int px,py,ex,ey;
		px = pt1.x;
		ex = pt2.x;
		py = pt1.y;
		ey = pt2.y;

		int m;
		//float m = (float)(pt2.y - pt1.y)/(pt2.x - pt1.x);
		if(pt2.x - pt1.x == 0)
		{
			m = 1;
		}
		else
			m = (int)(pt2.y - pt1.y)/(pt2.x - pt1.x);

		//if the slope is less then 1
		//I really wish i could draw what i was doing though...
		//Implements the drawing for all angles that is less then 45 degrees
		if(abs(m) < 1)
		{
			if(px > ex)
			{
				px = pt2.x;
				ex = pt1.x;
				py = pt2.y;
				ey = pt1.y;
			}
			int dx = ex - px;
			int dy = ey - py;
			int cy = 0;
			if(py > ey)
			{
				cy =-1;
				dy = py - ey;
			}
			else
				cy = 1;
			int d = 2*dy - dx;
			int Left = dy;
			int Top = (dy - dx);

			for(px; px <= ex; ++px)
			{
				PGraphics->AddPoint(px,py,color);
				if(d>0)
				{
					d = d + Top;
					py += cy;
				}
				else
				{
					d += Left;
				}
			}
		}
		//Implements all the angles that is greater then 45 degrees
		else
		{
				//checks to see if i need to flip the line.
			if(pt1.y > pt2.y)
			{
				py = pt2.y;
				ey = pt1.y;
				px = pt2.x;
				ex = pt1.x;
			}
			int dx = px - ex;
			int dy = py - ey;
			int cx = 0;
				//checks to see if i need to move x posatively or negativly
			if(px > ex)
			{
				cx =-1;
				dx = ex - px;
			}
			else
				cx = 1;

			int d = 2*dx - dy;
			int Top = dx;
			
			int Left = (dx - dy);

			for(py; py<=ey;++py)
			{
				PGraphics->AddPoint(px,py,color);
				if(d>0)
				{
					d += Top;
				}
				else
				{
					d += Left;
					px += cx; 
				}
			}
		}
}