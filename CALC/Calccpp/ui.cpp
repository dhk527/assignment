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
	CAdd add;
	CSub sub;
	CDiv div;
	CMul mul;
	CCalc* Addr_operator[4]={&add,&sub,&div,&mul};//포인터 배열을 이용하여 객체의 주소값을 나열.

	char input[7]={};
	double a,b;
	const char* set_operator[4]={"add(,)","sub(,)","div(,)","mul(,)"};
	// cpp는 문자열 선언 시 cosnt로 read-only임을 명시해야함.
	// const는 가독성 향상 및 안전성 의도를 명확하게 할 수 있게 됨.
	int done=0;

	while(done != 1)
	{
		CCalc *pCCalc=NULL; // CCalc의 주소를 가리키는 pCCalc을 초기화.
		Set_Operand(input,&a,&b);
		int Is_valid_operate = 0;

		while(1)
		{
			for(int i=0;i<4;i++)
				if(!strcmp(input,set_operator[i]))
				{
					pCCalc=Addr_operator[i];		// strcmp에서 연산 형식이 맞는 요소의 값을 pCCalc에 대입 시킴.
					cout<<pCCalc->ccalc(&a,&b)<<endl; // pCCalc은 대입받은 객체의 멤버함수 접근하기 위해 화살표 연산자를 이용해
					Is_valid_operate = 1;							// cca1c함수에 접근시켜서 연산 값을 얻어옵니다. 그것을 콘솔 출력창에 출력.
					break;
				}

			if(Is_valid_operate != 1) // 제대로 타입이 되지 않았을 시, event 발생.
			{
				fprintf(stderr,"제대로 입력하세요");
				while(getchar() != '\n');
			}
			getchar();
			break;
		}
		puts("done?");
		puts("[1]Yes, [0]No");
		scanf(" %d",&done);
	}
};

