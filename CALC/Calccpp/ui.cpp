#include <iostream>
#include <cstring>
#include "cal.h"
#include "ui.h"

void Set_Operand(char* input, double *pa, double *pb)
{
	system("clear");
	cout<<"터미널창에 Operator(operand 1,operand 2) 입력하시오"<<endl;
	scanf(" %4c%le%1c%le%1c",input,pa,input+4,pb,input+5);
};

void EventLoop()
{
	char input[7]={};
	double a,b;
	const char* set_operator[4]={"add(,)","sub(,)","div(,)","mul(,)"};
	// cpp는 문자열 선언 시 cosnt로 read-only임을 명시해야함.
	int done=0;

	while(done != 1)
	{	
		while(1)
		{
			Set_Operand(input,&a,&b);
			if(!strcmp(input,set_operator[0]))
			{
				CAdd add;
				add.ccalc(&a,&b);
				break;
			}

			if(!strcmp(input,set_operator[1]))
			{
				CSub sub;
				sub.ccalc(&a,&b);
				break;
			}

			if(!strcmp(input,set_operator[2]))
			{
				CDiv div;
				div.ccalc(&a,&b);
				break;
			}

			if(!strcmp(input,set_operator[3]))
			{
				CMul mul;
				mul.ccalc(&a,&b);
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
};
