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
	double a;
	double b;
	char* operator[4]={"add(,)","sub(,)","div(,)","mul(,)"};
	void* calc_arry[4]={Add, Sub, Div, Mul};
	char input[7]={};
	int done=0;

	while(done != 1)
	{	
		Set_Operand(input,&a,&b);
		for(int i=0 ; i<4; i++)
		{
			if(!strcmp(input,operator[i]))
				call_calc(calc_arry[i],a,b);
		}
		puts("done?");
		puts("[0]No, [1]Yes");
		scanf("%d",&done);
	}

}
/*	   while(1)
	   {
	   Set_Operand(input,&a,&b);
	   if(!strcmp(input,operator[0]))
	   {
	   call_calc(Add,a,b);
	   break;
	   }

	   if(!strcmp(input,operator[1]))
	   {
	   call_calc(Sub,a,b);
	   break;
	   }

	   if(!strcmp(input,operator[2]))
	   {
	   call_calc(Div,a,b);
	   break;
	   }

	   if(!strcmp(input,operator[3]))
	   {
	   call_calc(Mul,a,b);
	   break;
	   }
	   else
	   {
	   puts("제대로 입력하세요");
	   while(getchar() != '\n');
	   break;
	   }
	   }*/



	   
