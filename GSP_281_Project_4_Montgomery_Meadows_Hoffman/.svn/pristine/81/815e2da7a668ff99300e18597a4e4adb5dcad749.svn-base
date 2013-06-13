#ifndef FORCES_H
#define FORCES_H
#include "BaseEntity.h"
namespace FORCE
{
	void CaculateSpringForce(Spring &spr, BaseEntity &base)
	{

	}
	void CaculateGravityForce(BaseEntity &base)
	{

	}
	void CaculateBlastForce(Vector3 &pos, float power, BaseEntity &Base)
	{

	}
	void CaculateBouncy(BaseEntity &base)
	{

	}
	float CaculateImpulse(float Elasticity,float Mass1,float Mass2, float ClosingVel)
	{
		return (-(1 + Elasticity) * ClosingVel)/ ((1/Mass1) + (1/Mass2));
	}
	float CaculateAngularImpulse(float Elasticity, float Mass1, float Mass2, float ClosingVel, float I1, float I2)
	{
		return( -(1 + Elasticity)*ClosingVel)/((1/Mass1) + (1/Mass2) +std::pow(I1,2) + std::pow(I2,2));
	}

}


#endif