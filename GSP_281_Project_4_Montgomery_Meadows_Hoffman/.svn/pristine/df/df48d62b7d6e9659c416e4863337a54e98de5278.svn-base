#include "Vector3.h"

//Constructor
Vector3::Vector3()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}
//Seting the scale
void Vector3::Scale(float s)
{
	this->x *= s;
	this->y *= s;
	this->z *= s;
}
//Constructor
Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
Vector3 Vector3::operator=(const Vector3 &vect)
{
	this->x = vect.x;
	this->y = vect.y;
	this->z = vect.z;
	return *this;
}
//Returns a zeroed out vector
Vector3 Zero(void)
{
	Vector3 vect;
	vect.x = 0;
	vect.y = 0;
	vect.z = 0;
	return vect;
}
Vector3 Vector3D(float x, float y, float z)
{
	Vector3 vect;
	vect.x = x;
	vect.y = y;
	vect.z = z;
	return vect;
}
//Overloaded division operator
Vector3 operator/(const Vector3 &lhs,const Vector3 &rhs)
{
	Vector3 vect;
	vect.x = lhs.x / rhs.x;
	vect.y = lhs.y / rhs.y;
	vect.z = lhs.z / rhs.z;
	return vect;
}
//Overloaded + operator
Vector3 operator+(const Vector3 &rhs,const Vector3 &lhs)
{
	Vector3 vect;
	vect.x = rhs.x + lhs.x;
	vect.y = rhs.y + lhs.y;
	vect.z = rhs.z + lhs.z;
	return vect;
}
//Overloaded - operator
Vector3 operator-(const Vector3 &rhs,const Vector3 &lhs)
{
	Vector3 vect;
	vect.x = rhs.x - lhs.x;
	vect.y = rhs.y - lhs.y;
	vect.z = rhs.z - lhs.z;
	return vect;
}
//Overloaded * operator
Vector3 operator*(const Vector3 &rhs,const Vector3 &lhs)
{
	Vector3 vect;
	vect.x = rhs.x * lhs.x;
	vect.y = rhs.y * lhs.y;
	vect.z = rhs.z * lhs.z;
	return vect;
}
//Overloaded += operator
Vector3 operator+=(Vector3 &lhs, const Vector3 &rhs)
{
	lhs.x += rhs.x;
	lhs.y += rhs.y;
	lhs.z += rhs.z;
	return lhs;
}
//Overloaded -= operator
Vector3 operator-=(Vector3 &lhs, const Vector3 &rhs)
{
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;
	lhs.z -= rhs.z;
	return lhs;
}
//Overloaded /= operator
Vector3 operator/=(Vector3 &lhs, const Vector3 &rhs)
{
	lhs.x /= rhs.x;
	lhs.y /= rhs.y;
	lhs.z /= rhs.z;
	return lhs;
}
//Overloaded *= operator
Vector3 operator*=(Vector3 &lhs, const Vector3 &rhs)
{
	lhs.x *= rhs.x;
	lhs.y *= rhs.y;
	lhs.z *= rhs.z;
	return lhs;
}
//Vector3 operator=(Vector3 &lhs, const Vector3 &rhs)
//{
//	lhs.x = rhs.x;
//	lhs.y = rhs.y;
//	return lhs;
//}
//get the magnitude of a vector
double Vector3::Magnitude(void)const
{
	return std::sqrt(std::pow(this->x,2) + std::pow(this->y,2) + std::pow(this->z,2));
}
//Normalize a vector
void Vector3::normalize(void)
{
	double mag = Magnitude();
	this->x /= (float)mag;
	this->y /= (float)mag;
	this->z /= (float)mag;
}
//Get the absalut value
Vector3 Vector3::Abs(void)const
{
	Vector3 vect;
	if(x< 0)
		vect.x = x*-1;
	if(y<0)
		vect.y = y*-1;
	if(z<0)
		vect.z = z*-1;

	return vect;
}
//Get the Distance between two points.
Vector3 Vector3::Cross(const Vector3 &vect2)const
{
	Vector3 vect;
	vect.x = vect2.z*y - vect2.y * z;
	vect.y = x*vect2.z - vect2.z * x;
	vect.z = x*vect2.y - vect2.x * y;
	return vect;
}
double Vector3::Distance(const Vector3 &vect) const
{
	return std::sqrt(std::pow(vect.x - x,2) + std::pow(vect.y - y,2) + std::pow(vect.z - z,2));
}