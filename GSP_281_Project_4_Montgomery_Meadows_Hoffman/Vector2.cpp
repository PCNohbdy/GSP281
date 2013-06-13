#include "Vector2.h"

//Constructor
Vector2::Vector2()
{
	this->x = 0;
	this->y = 0;
}
//Seting the scale
void Vector2::Scale(float s)
{
	this->x *= s;
	this->y *= s;
}
//Constructor
Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}
Vector2 Vector2::operator=(const Vector2 &vect)
{
	this->x = vect.x;
	this->y = vect.y;
	return *this;
}
//Returns a zeroed out vector
Vector2 Zero(void)
{
	Vector2 vect;
	vect.x = 0;
	vect.y = 0;
	return vect;
}
Vector2 Vector2D(float x, float y)
{
	Vector2 vect;
	vect.x = x;
	vect.y = y;
	return vect;
}
//Overloaded division operator
Vector2 operator/(const Vector2 &lhs,const Vector2 &rhs)
{
	Vector2 vect;
	vect.x = lhs.x / rhs.x;
	vect.y = lhs.y / rhs.y;
	return vect;
}
//Overloaded + operator
Vector2 operator+(const Vector2 &rhs,const Vector2 &lhs)
{
	Vector2 vect;
	vect.x = rhs.x + lhs.x;
	vect.y = rhs.y + lhs.y;
	return vect;
}
//Overloaded - operator
Vector2 operator-(const Vector2 &rhs,const Vector2 &lhs)
{
	Vector2 vect;
	vect.x = rhs.x - lhs.x;
	vect.y = rhs.y - lhs.y;
	return vect;
}
//Overloaded * operator
Vector2 operator*(const Vector2 &rhs,const Vector2 &lhs)
{
	Vector2 vect;
	vect.x = rhs.x * lhs.x;
	vect.y = rhs.y * lhs.y;
	return vect;
}
//Overloaded += operator
Vector2 operator+=(Vector2 &lhs, const Vector2 &rhs)
{
	lhs.x += rhs.x;
	lhs.y += rhs.y;
	return lhs;
}
//Overloaded -= operator
Vector2 operator-=(Vector2 &lhs, const Vector2 &rhs)
{
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;
	return lhs;
}
//Overloaded /= operator
Vector2 operator/=(Vector2 &lhs, const Vector2 &rhs)
{
	lhs.x /= rhs.x;
	lhs.y /= rhs.y;
	return lhs;
}
//Overloaded *= operator
Vector2 operator*=(Vector2 &lhs, const Vector2 &rhs)
{
	lhs.x *= rhs.x;
	lhs.y *= rhs.y;
	return lhs;
}
//Vector2 operator=(Vector2 &lhs, const Vector2 &rhs)
//{
//	lhs.x = rhs.x;
//	lhs.y = rhs.y;
//	return lhs;
//}
//get the magnitude of a vector
double Vector2::Magnitude(void)const
{
	return std::sqrt(std::pow(this->x,2) + std::pow(this->y,2));
}
//Normalize a vector
void Vector2::normalize(void)
{
	double mag = Magnitude();
	this->x /= (float)mag;
	this->y /= (float)mag;
}
//Get the absalut value
Vector2 Vector2::Abs(void)const
{
	Vector2 vect;
	if(x< 0)
		vect.x = x*-1;
	else
		vect.x = x;
	if(y<0)
		vect.y = y*-1;
	else
		vect.y = y;

	return vect;
}
Vector2 Vector2::Inverse()const
{
	Vector2 vect;
	vect.x = -y;
	vect.y = x;
	return vect;
}
float Vector2::PerpDot(const Vector2 &vect)const
{
	Vector2 I = Inverse();
	return I.x * vect.x + I.y * vect.y;
}
float Vector2::PerpDot(const float d)const
{
	Vector2 I = Inverse();
	return I.x * d + I.y *d;
}
//Get the Distance between two points.
double Vector2::Distance(const Vector2 &vect) const
{
	return std::sqrt(std::pow(vect.x - x,2) + std::pow(vect.y - y,2));
}