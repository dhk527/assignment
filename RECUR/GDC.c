#include <stdio.h>

void GDC(int* numerator, int* denominator)
{
	int remainder;

	remainder = (*numerator) % (*denominator); // 유클리드 호제법
	*numerator = *denominator;
	
	if (remainder==0)
	{
	printf("%d\n",(*denominator));
	return ;
	}

	*denominator=remainder;


	GDC(numerator, denominator); // 재귀호출
}
	


int main()
{	
	int numerator;
	int denominator;

	puts("first");
	scanf("%d",&numerator);
	puts("second");
	scanf("%d",&denominator);

	GDC(&numerator, &denominator);

}
