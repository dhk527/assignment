#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"
#include "calc.h"

void GetValue(double* a ,double* b)
{
	puts("첫 번째 값을 입력하시오");
	scanf(" %d",a);
	puts("두 번째 값을 입력하시오");
	scanf(" %d",b);
}

MENU Printmenu()
{
	MENU input=0;

	system("clear");
	printf("[1]ADD\t[2]SUB\t[3]DIV\t[4]MUL\t[0]Exit\n");
	while((scanf("%d%*c",(int*)&input))==0)
	{
		puts("type number, not string");
		while (getchar() != '\n');
	}
	return input;
}

void EventLoop()
{
	double* a;
	double* b;

	MENU menu=0;

	while((menu=Printmenu())!=0)
	{
		switch (menu)
		{
			case ADD:
				GetValue(&a,&b);
				call_calc(Add,a,b);
				break;

			case SUB:
				break;

			case DIV:
				break;

			case MUL:
				break;

			default:
				break;

		}
		getchar();

	}

}
