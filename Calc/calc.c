#include <stdio.h>
#include "calc.h"

double add(double a, double b)
{
	return a + b;
}

double sub(double a, double b) 
{
	return a - b;
}

double Div(double a, double b) 
{
	if (b != 0) {
		return a / b;
	}else{
		printf("Error: Division by zero\n");
		return 0.0; 
	}
}

double mul(double a, double b) 
{
	return a * b;
}

double call_calc(calc select_type,double a,double b)
{
	select_type(a,b);
	return select_type;
}

