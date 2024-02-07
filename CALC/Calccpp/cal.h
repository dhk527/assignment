#ifndef CAL_H
#define CAL_H

#include <iostream>
using namespace std;

class CCalc 
{
	public:
		virtual void ccalc(double* pa, double* pb)=0;
};

class CAdd : public CCalc
{
	public:
		void ccalc(double* pa, double* pb);
};

class CSub : public CCalc 
{
	public:
		void ccalc(double* pa, double* pb);
};

class CDiv : public CCalc 
{
	public:
		void ccalc(double* pa, double* pb);
};

class CMul : public CCalc 
{
	public:
		void ccalc(double* pa, double* pb);
};

#endif 

