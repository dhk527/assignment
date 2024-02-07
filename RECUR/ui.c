#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GCD.h"
#include "ui.h"

void SetValue(int* pa ,int* pb)
{
	puts("두 값을 입력하시오 ex)number1 number2");
	while((scanf("%d %d",pa,pb))!=2)
	{
		puts("제대로 숫자를 치세요");
		while (getchar() !='\n');
	}
}

MENU Printmenu()
{
	MENU input=0;

	system("clear");
	puts("[1]Operation\t[0]Exit");
	while((scanf("%d%*c",(int*)&input))==0)
	{
		puts("type number, not string");
		while (getchar() != '\n');
	}
	return input;
}

void EventLoop()
{
	int numerator;
	int denominator;

	MENU menu=0;

	while((menu=Printmenu())!=0)
	{
		switch (menu)
		{
			case Operation:
				SetValue(&numerator, &denominator);
				
				int origin_numerator=numerator;
				int origin_denominator=denominator;

				GCD(&numerator, &denominator);
				view_value(&origin_numerator,&origin_denominator,&denominator);
				break;

			case EXIT:
				break;


			default:
				break;

		}
		getchar();
		getchar();

	}

}
