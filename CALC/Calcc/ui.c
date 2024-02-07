#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ui.h"
#include "calc.h"

void Set_Operand(char* input, double *pa, double *pb)
{
	system("clear");
	puts("터미널창에 Operator(operand 1,operand 2) 입력하시오");
	scanf(" %4c%le%c%le%c",input,pa,input+4,pb,input+5);
}

void EventLoop()
{
	double a;
	double b;
	char* operator[4]={"add(,)","sub(,)","div(,)","mul(,)"};
	char input[7]={0};
	int done=0;

	while(done != 1)
	{	
		while(1)
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
		}
		puts("done?");
		puts("[1]Yes, [0]No");
		scanf("%d",&done);
	}

}
