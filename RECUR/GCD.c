#include <stdio.h>
#include "ui.h"

void GCD(int* numerator, int* denominator)
{
	int remainder;

	remainder = (*numerator) % (*denominator); // 유클리드 호제법
	
	if (remainder==0)
	{
	return ;
	}

	*numerator = *denominator;
	*denominator=remainder;

	GCD(numerator, denominator); // 재귀 함수 호출
}

void view_value(int* origin_numerator,int* origin_denominator,int* GCD_val)
{
	putchar('\n');
	printf("GCD : %d\n",*GCD_val);
	printf("LCM : %d\n",(((*origin_numerator)*(*origin_denominator))/(*GCD_val)));
	printf("a/b : %d/%d to simple form fraction c/d : %d/%d \n"
	,*origin_numerator, *origin_denominator, *origin_numerator/(*GCD_val), *origin_denominator/(*GCD_val));
}



