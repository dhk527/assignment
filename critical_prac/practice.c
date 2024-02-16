#include <stdio.h>

int GetFactorial(int nParam)
{
	int nResult = 0; // 조건
	if (nParam == 1) return 1; // 모두 끝나면 제일 마지막 스택부터 하나씩 반환.
							  // return 될 때까지 계속 호출함.

	nResult = nParam * GetFactorial(nParam -1);// 증감 부분 = 재귀 호출
	return nResult;
}

void PutData(char* pszParam)
{
	if(*pszParam == '\0') // 조건 
		return;// 모두 끝나면 제일 위로 쌓인 스택부터 하나씩 반환.
			  // return 될 때까지 계속 호출 한다.

	//putchar(*pszParam); // 일단 뱉어
	PutData(pszParam+1);// 증감부분 = 재귀 호출
	putchar(*pszParam); // 나중에 뱉어가 됨
}

int main()
{
	printf("5! == %d\n", GetFactorial(5));
	PutData("TestData");
	putchar('\n');

	return 0;
}
