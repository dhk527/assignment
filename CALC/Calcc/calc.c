#include <stdio.h>
#include "calc.h"

double Add(double a, double b)
{
	return a + b;
}

double Sub(double a, double b) 
{
	return a - b;
}

double Div(double a, double b) 
{
	if (b != 0) 
		return a / b;
	else
	{
		printf("Error: Division by zero\n");
		return 0.0; 
	}
}

double Mul(double a, double b) 
{
	return a * b;
}

//double call_calc(double (*select_type)(double a, double c),double a,double b) // 형식 재선언하지 않을 시,

void call_calc(calc select_type,double a, double b) // 연산 기능 함수 호출 및 Set_Operand의 parameter 중, *pa, *pb 값인 피연산자를 받음.
{
	double result = select_type(a,b);
	printf("연산 값은 %.3lf\n",result);
	getchar();
}

