#ifndef Vector3_H
#define Vector3_H
#include<cmath>
class Vector3
{
public:
	float x,y,z;
	Vector3();
	Vector3(float x, float y, float z);
	friend Vector3 Zero3D(void);
	friend Vector3 Vector3D(float x, float y,float z);
	void normalize(void);
	void Scale(float t);
	Vector3 Abs(void) const;
	Vector3 Cross(const Vector3 &vect2) const;
	double Magnitude(void)const;
	double Distance(const Vector3 &vect)const;
	friend Vector3 operator/(const Vector3 &lhs, const Vector3 &rhs);
	friend Vector3 operator*(const Vector3 &lhs, const Vector3 &rhs);
	friend Vector3 operator+(const Vector3 &lhs, const Vector3 &rhs);
	friend Vector3 operator-(const Vector3 &lhs, const Vector3 &rhs);
	friend Vector3 operator+=(Vector3 &lhs, const Vector3 &rhs);
	friend Vector3 operator-=(Vector3 &lhs, const Vector3 &rhs);
	friend Vector3 operator/=(Vector3 &lhs, const Vector3 &rhs);
	friend Vector3 operator*=(Vector3 &lhs, const Vector3 &rhs);
	Vector3 operator=(const Vector3 &rhs);
	float Dot(const Vector3 &vect)const{return x*vect.x + y*vect.y + z*vect.z;}
	float Dot(const float d)const {return x*d + y*d + z*d;}
	Vector3 operator*(float num) const
	{
		Vector3 vect;
		vect.x = x * num;
		vect.y = y * num;
		vect.z = z * num;
		return vect;
	}
	friend Vector3 operator*(const float num, const Vector3 &vect2)
	{
		Vector3 vect;
		vect.x = vect2.x * num;
		vect.y = vect2.y * num;
		vect.z = vect2.z * num;
		return vect;
	}
	Vector3 operator+(float num) const
	{
		Vector3 vect;
		vect.x = x + num;
		vect.y = y + num;
		vect.z = z + num;
		return vect;
	}
	friend Vector3 operator+(float num, const Vector3 &vect2)
	{
		Vector3 vect;
		vect.x = vect2.x + num;
		vect.y = vect2.y + num;
		vect.z = vect2.z + num;
		return vect;
	}
	Vector3 operator-(float num) const
	{
		Vector3 vect;
		vect.x = x - num;
		vect.y = y - num;
		vect.z = z - num;
		return vect;
	}
	friend Vector3 operator-(float num, const Vector3 &vect2)
	{
		Vector3 vect;
		vect.x = -vect2.x + num;
		vect.y = -vect2.y + num;
		vect.z = -vect2.z + num;
		return vect;
	}
	Vector3 operator/(float num) const
	{
		Vector3 vect;
		vect.x = x / num;
		vect.y = y / num;
		vect.z = z / num;
		return vect;
	}
	friend Vector3 operator/(float num, const Vector3 &vect2)
	{
		Vector3 vect;
		vect.x =  num/ vect2.x;
		vect.y =  num/ vect2.y;
		vect.z =  num/ vect2.z;
		return vect;
	}

};



#endif