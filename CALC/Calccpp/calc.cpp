#include <iostream>
using namespace std;

class CCalc
{
public:
	virtual double ccalc(const double a, const double b)
	{
		return puts("no operate");
	};
};

class CAdd : public CCalc
{
public:
	double ccalc(const double a, const double b)
	{
		return a+b;
	};
};

class CSub : public CCalc
{
public:
	double ccalc(const double a, const double b)
	{
		return a-b;
	}
};

class CDiv : public CCalc
{
public:
	double ccalc(const double a, const double b)
	{
		if(b!=0)
			return a/b;
		else
			cerr<<"Error : Division by zero";
			return 0;
	}
};

class CMul : public CCalc
{
public:
	void ccalc(const double a, const double b)
	{
	double result = a*b;
	 cout << "a*b" << result << endl;
	}
};

void SetValue(double* a, double* b)
{
	cout << "first: ";
	cin >> *a;

	cout << "second: ";
	cin >> *b;
}

int main()
{
	double a,b;
	SetValue(&a,&b);
	
	CAdd add;
add;

	GetValue;
	CSub sub;
	CDiv div;
	CMul mul;

	return 0;
}
