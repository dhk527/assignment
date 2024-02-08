#include "cal.h"
#include <climits>
void CAdd::ccalc(double* pa, double* pb)
{
	double result = (*pa) + (*pb);
	cout << result << endl;
}

void CSub::ccalc(double* pa, double* pb)
{
	double result = (*pa) - (*pb);
	cout << result << endl;
}

void CDiv::ccalc(double* pa, double* pb)
{
	if (*pb != 0)
	{
		double result = (*pa) / (*pb);
		cout << result << endl;
	}
	else 
		cerr << "Error : Division by zero" <<  endl;
}

void CMul::ccalc(double* pa, double* pb)
{
	double result = (*pa) * (*pb);
	cout << result << endl;
}

