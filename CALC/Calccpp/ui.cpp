#include <iostream>
#include <stdio.h>
#include "cal.h"
#include "ui.h"

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
};
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
