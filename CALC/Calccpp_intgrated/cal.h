#ifndef CAL_H
#define CAL_H

#include <iostream>
#include <climits>
using namespace std;
void cin_fail();

class CCalc 
{
	public:
		void SetValue(double* pa, double* pb);
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

