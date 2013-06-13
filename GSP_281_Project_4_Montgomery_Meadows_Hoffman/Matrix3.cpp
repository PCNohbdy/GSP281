#include "Matrix3.h"
//My Matrix Vector class
#define PI      3.1415926535897932384626433832795
using namespace std;
//Constructor
Matrix3::Matrix3()
{
	this->Identity();
}
//Copying one matrix
Matrix3::Matrix3(Matrix3 &vect)
{
	for (long i = 0; i < 3; i++)
		for (long j = 0; j < 3; j++)
			this->m[j][i] = vect.m[j][i];
}
//Set the identity
void Matrix3::Identity()
{
	for (long i = 0; i < 3; i++)
		for (long j = 0; j < 3; j++)
			this->m[j][i] = (i == j) ? 1.0f : 0.0f;
}
//Transpose the matrix
void Matrix3::Transpose(const Matrix3 *vect)
{
	for(int y = 0; y < 3; ++y)
		for(int x = 0;x < 3; ++x)
		{
			this->m[x][y] = vect->m[y][x];
		}
}
//Transpose the matrix
void Matrix3::Transpose(const Vector2 *vect)
{
	this->m[0][2] += vect->x;
	this->m[1][2] += vect->y;
}
//Scale The matrix
void Matrix3::Scale(float x, float y)
{
	this->Identity();
	this->m[0][0] *= x;
	this->m[1][1] *= y;
}
//Rotate the matrix in deg
void Matrix3::RotDeg(float angle)
{
	float nangle = (float)(angle * PI / 180.0f);
	this->Identity();
	this->m[0][0] = cos(nangle);
	this->m[0][1] = -sin(nangle);
	this->m[1][0] = sin(nangle);
	this->m[1][1] = cos(nangle);
}
//Rotate Matrix in radians
void Matrix3::RotRad(float angle)
{
	this->Identity();
	this->m[0][0] = cos(angle);
	this->m[0][1] = -sin(angle);
	this->m[1][0] = sin(angle);
	this->m[1][1] = cos(angle);
}
//Adds two Matrixs together
Matrix3 operator+(const Matrix3 &lhs, const Matrix3 &rhs)
{
		Matrix3 temp;
	for(int y = 0; y < 3; ++y)
		for(int x = 0;x < 3; ++x)
		{
			temp.m[x][y] = rhs.m[x][y]+lhs.m[x][y];
		}
	return temp;
}
//Concat a matrix
Matrix3 operator*(const Matrix3 &lhs, const Matrix3 &rhs)
{
		Matrix3 temp;
	for(int y = 0; y < 3; ++y)
		for(int x = 0;x < 3; ++x)
		{
			temp.m[x][y] = rhs.m[0][y]*lhs.m[x][0] + rhs.m[1][y]*lhs.m[x][1] + rhs.m[2][y]*lhs.m[x][2];
		}
	return temp;
}
//Concat a matrix and a vector
Vector2 operator*(const Matrix3 &lhs, const Vector2 &rhs)
{
	Matrix3 temp;
	temp.Identity();
	Vector2 result;
	for(int y = 0; y < 2; ++y)
	{
			temp.m[0][y] = lhs.m[0][y]*rhs.x + lhs.m[1][y]*rhs.y + lhs.m[y][2];
	}
	result.x = temp.m[0][0];
	result.y = temp.m[0][1];
	return result;
}