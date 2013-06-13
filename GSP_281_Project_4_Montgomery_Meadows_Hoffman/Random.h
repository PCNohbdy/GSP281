#ifndef RANDOM_H
#define RANDOM_H
#include <time.h>
#include <cmath>
#include <assert.h>
#include <stdlib.h>
#define e 2.71828
#define RAND Random::Instance()
class Random
{
public:
	static Random* Instance(){static Random*ptr = new Random();return ptr;};
	void Set(float seed){Z = seed;};
	double rand(void){Z = fmod((A*Z+C),M); return Z/M;}
	double unifRand(){return rand()+1/double(RAND_MAX);}
	double unifRand(double a, double b){return (b-a)*unifRand()+a;}
	double unifRand(long n)
	{
		//make sure n is always positive
		if(n < 0) n = -n;
		//make sure n does not equ 0
		if(n ==0) return 0;
		//makes the Rand number
		long r = (long) (unifRand()*n)+1;
		//makes sure the rand number is not greater then the origional number;
		return (r > n) ? n:r;
	}
	double Exponentail(double a, double b)
	{
	
		//static double x = unifRand(0,a);
		assert(b>0.0);
		//x = 1 - pow(e, -(a/b);
		return a-b * log(unifRand(0,1));
	}
	double Weibull(double a, double b, double c)
	{
		assert(b>0.0 && c > 0.0);
		return a+b*std::pow(-log(unifRand(0,1)),1.0/c);
	}
	double triangular(double xMin,double xMax, double c)
	{
		assert(xMin < xMax && xMin <= c && c <= xMax);

		double p = unifRand(0,1);
		double q = 1.0 - p;
		if(p <= (c - xMin)/(xMax-xMin))
			return xMin + std::sqrt((xMax - xMin) * (c - xMin)*p);
		else
			return xMax - std::sqrt((xMax - xMin)*(xMax - c) * q);

	}
	double normal(double mu, double sigma)
	{
		assert(sigma > 0);
		double p,p1,p2;
		do
		{

			p1 = unifRand(-1,1);
			p2 = unifRand(-1,1);
			p = p1 * p1 + p2*p2;
		}while(p>=1.0);
		return mu + sigma * p1 * sqrt(-2. *log(p)/p);
	}
	int poisson(double mu)
		{
			assert(mu> 0);
			double b = 1.;
			int i;
			for(i=0;b>=exp(-mu);++i)
				b*=unifRand(0,1);
			return i -1;

		}
	double logarithmic(double xmin, double xmax)
	{
		assert(xmin< xmax);
		double a = xmin;
		double b = xmax - xmin;
		return a+b * unifRand(0,1)*unifRand(0,1);
	}
private:
	Random(){Z = 0;A = 56741;C=0;M = pow(2.0f,23.0f)-1;}
	float Z,A,C,M;
};
#endif
