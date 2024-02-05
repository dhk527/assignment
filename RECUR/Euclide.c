#include <stdio.h>

void GCD(int* numerator, int* denominator)
{
	int remainder;

	remainder = (*numerator) % (*denominator); // 유클리드 호제법
	*numerator = *denominator;
	
	if (remainder==0)
	{
	return ;
	}

	*denominator=remainder;


	GCD(numerator, denominator); // 재귀호출
}
	


int main()
{	
	int numerator;
	int denominator;
	int origin_numerator;
	int origin_denominator;

	puts("first");
	scanf("%d",&numerator);
	puts("second");
	scanf("%d",&denominator);
	origin_numerator=numerator;
	origin_denominator=denominator;

	GCD(&numerator, &denominator);
	printf("GCD : %d\n",denominator);
	printf("LCM : %d\n",(origin_numerator*origin_denominator)/(denominator));
}

