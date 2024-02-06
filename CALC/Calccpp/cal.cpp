#include "cal.h"
void cin_fail()
{
	if(cin.fail())
	{
		cerr << "do not type string, type number"<<endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	};
}

void CCalc::SetValue(double* pa, double* pb) 
{
	cout << "first: ";
	cin >> *pa;

	cout << "second: ";
	cin >> *pb;
}

void CAdd::ccalc(double* pa, double* pb) 
{
	double result = (*pa) + (*pb);
	cin_fail();
	cout << "a+b: " << result << endl;
}

void CSub::ccalc(double* pa, double* pb)
{
	double result = (*pa) - (*pb);
	cin_fail();
	cout << "a-b: " << result <<  endl;
}

void CDiv::ccalc(double* pa, double* pb)
{
	if (*pb != 0) {
		double result = (*pa) / (*pb);
		cin_fail();
		cout << "a/b: " << result <<  endl;
	} else {
		cerr << "Error : Division by zero" <<  endl;
	}
}

void CMul::ccalc(double* pa, double* pb)
{
	double result = (*pa) * (*pb);
	cin_fail();
	cout << "a*b: " << result <<  endl;
}

