#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <climits>

using namespace std;

void cin_fail()
{
	if(cin.fail())
	{
		cerr << "do not type string, type number"<<endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	};
}

class CCalc
{
	public:
		void SetValue(double* pa, double* pb)
		{
			cout << "first: ";
			cin >> *pa;

			cout << "second: ";
			cin >> *pb;
		}
		virtual void ccalc(double* pa, double* pb){};
};

class CAdd : public CCalc
{
	public:
		void ccalc(double* pa, double* pb)
		{
			double result = (*pa)+(*pb);
			cin_fail();
			cout << "a+b: " << result << endl;
		}
};

class CSub : public CCalc
{
	public:
		void ccalc(double* pa, double* pb)
		{
			double result = (*pa)-(*pb);
			cin_fail();
			cout << "a-b: " << result << endl;
		}
};

class CDiv : public CCalc
{
	public:
		void ccalc(double* pa, double* pb)
		{
			if(*pb!=0)
			{
				double result = (*pa)/(*pb);
				cin_fail();
				cout << "a/b: " << result << endl;
			}else
				cerr<<"Error : Division by zero";
		}
};


class CMul : public CCalc
{
	public:
		void ccalc(double* pa, double* pb)
		{
			double result = (*pa)*(*pb);
			cin_fail();
			cout << "a*b: " << result << endl;
		}
};

typedef enum MENU {EXIT, ADD, SUB, DIV, MUL} MENU;

MENU Printmenu()
{
	MENU input=EXIT;

	system("clear");
	printf("[1]CAdd\t[2]CSub\t[3]CDiv\t[4]CMul\t[0]Exit\n");
	while((scanf("%d%*c",(int*)&input))==0)
	{
		puts("type number, not string");
		while (getchar() != '\n');
	}
	return input;
}

void EventLoop()
{
	double a,b;
	MENU menu=EXIT;
	while((menu=Printmenu())!=0)
	{
		switch (menu)
		{
			case ADD:
				{
					CAdd add;
					add.SetValue(&a,&b);
					add.ccalc(&a,&b);
					break;
				}

			case SUB:
				{
					CSub sub;
					sub.SetValue(&a,&b);
					sub.ccalc(&a,&b);
					break;
				}

			case DIV:
				{
					CDiv div;
					div.SetValue(&a,&b);
					div.ccalc(&a,&b);
					break;
				}

			case MUL:
				{
					CMul mul;
					mul.SetValue(&a,&b);
					mul.ccalc(&a,&b);
					break;
				}

			default:
				break;
		}
		getchar();
		getchar();
	}
};

int main()
{
	EventLoop();
	return 0;
}
