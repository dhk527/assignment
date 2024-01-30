//여러 구조체 인스턴스들을 체인처럼 연결하는 포인터를 이용한 자료구조 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"
#include "singleList.h"

void Blockbufferflow(char* typeString)
{
	do{
		 if(strlen(typeString)>=31)
		 {
		 puts("do not exceed 31 byte in input");
		 int c;
		 while ((c = getchar()) != '\n' && c != EOF);
		 printf("please retype : ");
		 scanf("%31s",typeString);
		 }
	}while(strlen(typeString)>=31);
}

//buffer가 왜 있을까?
//buffer가 왜 생길까?

void CreateData()
{
	char Id[32];
	char Email[64];

	printf("\"Id\": ");
	scanf("%31s",Id);
	Blockbufferflow(Id);
	
	printf("\"Email\": ");
	scanf("%31s",Email);
	Blockbufferflow(Email);

	AddNewNode(Id, Email);
}


void InputToSearch()
{
	char Id[32];
	puts("Input your Id");
	scanf("%31s%*c",Id);
	Blockbufferflow(Id);
	SearchById(Id);
}

void InputToRemove()
{
	char Id[32];
	puts("Input \"id\" to delete ");
	scanf("%31s%*c",Id);
	Blockbufferflow(Id);
	RemoveNode(Id);
}

MENU Printmenu()
{
	MENU input=0;

	system("clear");
	printf("[1]NEW\t[2]Search\t[3]Print\t[4]Remove\t[0]Exit\n");
	while((scanf("%d%*c",(int*)&input))==0)
	{
		puts("type number, not string");
		while (getchar() != '\n');
	}
	return input;
}

void EventLoop()
{
	MENU menu=0;

	while((menu=Printmenu())!=0)
	{
		switch (menu)
		{
			case NEW:
				CreateData();
				break;

			case SEARCH:
				InputToSearch();
				break;

			case PRINT:
				PrintList();
				break;

			case REMOVE:
				InputToRemove();
				break;

			default:
				ReleasesList();
				break;

		}
		getchar();

	}

}
