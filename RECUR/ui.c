#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GCD.h"
#include "ui.h"

void SetValue(int* pa ,int* pb) // console 출력창에, GCD할 두 피연산자를 set
{
	puts("두 값을 입력하시오 ex)number1 number2");
	while((scanf("%d %d",pa,pb))!=2)
	{
		puts("제대로 숫자를 치세요");
		while (getchar() !='\n');
	}
}


void view_value(int* origin_numerator,int* origin_denominator,int* GCD_val) // console출력 창(터미널)에 결과값을 확인
{
	putchar('\n');
	printf("GCD : %d\n",*GCD_val);
	printf("LCM : %d\n",(((*origin_numerator)*(*origin_denominator))/(*GCD_val)));// 초기의 두 값의 곱/GCD 값 = LCM 최소 공배수
	printf("a/b : %d/%d to simple form fraction c/d : %d/%d \n"
			,*origin_numerator, *origin_denominator, *origin_numerator/(*GCD_val), *origin_denominator/(*GCD_val));
	// 서로소는 1이외의 공약수가 없음을 일컫기 때문에 초기 값에서 최대공약수를 나눔.
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
