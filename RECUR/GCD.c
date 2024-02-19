/*
유클리드 호제법에서, 나머지 연산 시 계산된 값이 0이 된 시점의 분모값(denominator)이 GCD를 가짐.
최대 공약수를 가진다. GCD를 반환하지 않고 재귀호출을 이용해서 remainder가 0일 때, 분모의 값을 확인하여 구현.
*/
#include <stdio.h>
#include "ui.h"

void GCD(int* numerator, int* denominator) 
{									
	int remainder;
	remainder = (*numerator) % (*denominator);
	
	if (remainder==0)
		return ;

	*numerator = *denominator; // 재귀 호출 이후에 넣었을 시, segment fault 발생 (stack overflow)
	*denominator=remainder;

	GCD(numerator, denominator); // 재귀 호출, remainder가 0이 될 때, return을 시킴.
}								// 재귀 호출 : 함수가 자기 자신을 호출하는 구조, 가독성 및 코드 간결화
