#include <stdio.h>
#include "ui.h"

void GCD(int* numerator, int* denominator) // 유클리드 호제법을 이용하여 GCD 값을 구하기.
{
	int remainder;

	remainder = (*numerator) % (*denominator);
	
	if (remainder==0)
	{
	return ;
	}

	*numerator = *denominator; // 재귀 호출 이후에 넣었을 시, segment fault 발생 (stack overflow)
	*denominator=remainder;

	GCD(numerator, denominator); // 재귀 호출, remainder가 0이 될 때, return을 시킴.
}

void view_value(int* origin_numerator,int* origin_denominator,int* GCD_val) // console출력 창(터미널)에 결과값을 확인
{
	putchar('\n');
	printf("GCD : %d\n",*GCD_val);
	printf("LCM : %d\n",(((*origin_numerator)*(*origin_denominator))/(*GCD_val)));
	printf("a/b : %d/%d to simple form fraction c/d : %d/%d \n"
	,*origin_numerator, *origin_denominator, *origin_numerator/(*GCD_val), *origin_denominator/(*GCD_val));
}



