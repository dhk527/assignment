/* 
user interface 콘솔 입출력 소스 코드
연산자(피연산자1,피연사자2)를 콘솔 입력창에 입력한다. 
input에 양식에 맞게 입력이 됐을 시, 포인터 배열 operator를 이용하여 문자열 비교를 해서 양식에 맞을 시, 특정 연산 함수호출.
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ui.h"
#include "calc.h"

void Set_Operand(char* input, double *pa, double *pb) // 터미널창에 연산자와 피연산자를 초기화
{
	system("clear");
	puts("터미널창에 Operator(operand 1,operand 2) 입력하시오");
	scanf(" %4c%le%c%le%c",input,pa,input+4,pb,input+5);
}

void EventLoop() // 연산 이벤트 반복
{
	double a,b;
	const char* operator[4]={"add(,)","sub(,)","div(,)","mul(,)"};// 포인터 배열을 이용해 'a','s','d','m' 문자열의 첫번째 요소의 주소값을 가리킴.
	void* calc_arry[4]={Add, Sub, Div, Mul};//위와 마찬가지이나 함수명 즉 함수의 주소값을 가리킴.
	char input[7]={};// 모든 배열 요소 '\0' 초기화, 콘솔 입력을 통해 operator와 문자열 비교를 함.
	int done=0;
	while(done != 1)
	{	
		Set_Operand(input,&a,&b);
		int valid_operator = 0;

		for(int i=0;i<4;i++)
		{
			if(!strcmp(input,operator[i]))
			{
				call_calc(calc_arry[i],a,b);
				valid_operator=1;
				break;
			}
		}
		if(!valid_operator)
		{
			fprintf(stderr,"제대로 입력하시오\n");//굳이 stdout인 puts, printf를 안쓰는 이유는? 
												  //stderr는 null-buffering으로 성능은 떨어지지만, stdout은 프로그램 비정상 동작 시, 버퍼내용이 출력이 되지 않을 수 있음.
			while(getchar()!='\n');//입력 버퍼에 '\n'을 제외한 문자열을 비움.
		}

		puts("done?\n[0]No, [1]Yes");
		scanf("%d",&done);
	}

}
