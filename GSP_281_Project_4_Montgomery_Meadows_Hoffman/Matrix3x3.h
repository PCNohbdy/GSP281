#ifndef MATRIX3_H
#define MATRIX3_H
#include "Vector2.h"
class Matrix3
{
public:
	Matrix3();
	Matrix3(Matrix3 &vect);
	void Identity(void);
	void Transpose(const Matrix3 *vect);
	void Transpose(const Vector2 *vect);
	void Scale(float x, float y);
	void RotDeg(float angle);
	void RotRad(float angle);
	friend Matrix3 operator+(const Matrix3 &lhs, const Matrix3 &rhs);
	friend Matrix3 operator*(const Matrix3 &lhs, const Matrix3 &rhs);
	friend Vector2 operator*(const Matrix3 &lhs, const Vector2 &rhs);
	float m[3][3];

};



#endif