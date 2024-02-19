#ifndef CAL_H
#define CAL_H

#include <iostream>
using namespace std;

class CCalc // 추상 클래스 : cpp에서는 순수 가상 함수를 포함하는 클래스로서, 객체를 직접 생성할 수 없음
{
	public:
		virtual double ccalc(double*, double*) =0; // 연산 기능의 다형성을 위해, 상속시킬 원형 함수 시그니쳐를 선언
};							//가상 함수란? 다형성을 지원하는 객체 지향 언어에서 사용, 파생 클래스에서 재정의 되는 멤버 함수.
							//순수 가상 함수를 통해 강제로 재정의(override)를 시키게함.
							//코드의 일관성 및 코드 구현에서 생긴 실수를 강제로 방지.
class CAdd : public CCalc 
{
	public:
		double ccalc(double*, double*) override;
};

class CSub : public CCalc 
{
	public:
		double ccalc(double*, double*) override;
};

class CDiv : public CCalc 
{
	public:
		double ccalc(double*, double*) override;
};

class CMul : public CCalc 
{
	public:
		double ccalc(double*, double*) override;
};

#endif 

