#ifndef CAL_H
#define CAL_H

#include <iostream>
using namespace std;

class CCalc // 연산 기능의 다형성을 위해, 상속시킬 원형 함수 시그니쳐를 선언 및 순수 가상 함수로 강제로 재정의를 시키게함. 
{
	public:
		virtual void ccalc(double*, double*) =0;
};

class CAdd : public CCalc
{
	public:
		void ccalc(double*, double*);
};

class CSub : public CCalc 
{
	public:
		void ccalc(double*, double*);
};

class CDiv : public CCalc 
{
	public:
		void ccalc(double*, double*);
};

class CMul : public CCalc 
{
	public:
		void ccalc(double*, double*);
};

#endif 

