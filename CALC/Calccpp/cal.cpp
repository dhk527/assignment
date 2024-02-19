#include "cal.h"

//다형성:객체간에 동일한 클래스를 가지면서도 실제 수행되는 구현은 다름을 나타내는 개념.
//인터페이스? 클래스가 어떤 동작을 제공하는 지, 명시적으로 정의한 추상화..

double CAdd::ccalc(double* pa, double* pb)
{
	return (*pa) + (*pb);
}

double CSub::ccalc(double* pa, double* pb)
{
	return (*pa) - (*pb);
}

double CDiv::ccalc(double* pa, double* pb)
{
	if (*pb != 0)
		return (*pa) / (*pb);
	else
	{
		cerr << "Error : Division by zero" <<  endl;
		return -1.0;
	}
}

double CMul::ccalc(double* pa, double* pb)
{
	return (*pa) * (*pb);
}

