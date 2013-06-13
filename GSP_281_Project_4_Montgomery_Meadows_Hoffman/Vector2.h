#ifndef VECTOR2_H
#define VECTOR2_H
#include<cmath>

class Vector2
{
public:
	float x,y;
	Vector2();
	Vector2(float x, float y);
	friend Vector2 Zero(void);
	friend Vector2 Vector2D(float x, float y);
	void normalize(void);
	void Scale(float t);
	Vector2 Abs(void) const;
	Vector2 Inverse(void) const;
	double Magnitude(void)const;
	double Distance(const Vector2 &vect)const;
	friend Vector2 operator/(const Vector2 &lhs, const Vector2 &rhs);
	friend Vector2 operator*(const Vector2 &lhs, const Vector2 &rhs);
	friend Vector2 operator+(const Vector2 &lhs, const Vector2 &rhs);
	friend Vector2 operator-(const Vector2 &lhs, const Vector2 &rhs);
	friend Vector2 operator+=(Vector2 &lhs, const Vector2 &rhs);
	friend Vector2 operator-=(Vector2 &lhs, const Vector2 &rhs);
	friend Vector2 operator/=(Vector2 &lhs, const Vector2 &rhs);
	friend Vector2 operator*=(Vector2 &lhs, const Vector2 &rhs);
	Vector2 operator=(const Vector2 &rhs);
	float Dot(const Vector2 &vect)const{return x*vect.x + y*vect.y;}
	float PerpDot(const Vector2 &vect)const;
	float PerpDot(const float d)const;
	float Dot(const float d)const {return x*d + y*d;}
	Vector2 operator*(float num) const
	{
		Vector2 vect;
		vect.x = x * num;
		vect.y = y * num;
		return vect;
	}
	friend Vector2 operator*(float num, const Vector2 &vect2)
	{
		Vector2 vect;
		vect.x = vect2.x * num;
		vect.y = vect2.y * num;
		return vect;
	}
	Vector2 operator+(float num)
	{
		Vector2 vect;
		vect.x = x + num;
		vect.y = y + num;
		return vect;
	}
	friend Vector2 operator+(float num, const Vector2 &vect2)
	{
		Vector2 vect;
		vect.x = vect2.x + num;
		vect.y = vect2.y + num;
		return vect;
	}
	Vector2 operator-(float num) const
	{
		Vector2 vect;
		vect.x = x - (float)num;
		vect.y = y - (float)num;
		return vect;
	}
	friend Vector2 operator-(float num, const Vector2 &vect2)
	{
		Vector2 vect;
		vect.x = -vect2.x + num;
		vect.y = -vect2.y + num;
		return vect;
	}
	Vector2 operator/(float num) const
	{
		Vector2 vect;
		vect.x = x / num;
		vect.y = y / num;
		return vect;
	}
	friend Vector2 operator/(float num, const Vector2 &vect2)
	{
		Vector2 vect;
		vect.x =  num/ vect2.x;
		vect.y =  num/ vect2.y;
		return vect;
	}
	//bool operator==(const Vector2 &vect1, const Vector2 &vect2)
};
#endif
