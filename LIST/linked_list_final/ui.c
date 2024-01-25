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
		 while ((c = getchar()) != '\n'&& c != EOF);// 입력 버퍼 지우기 
		 printf("please retype : ");
		 scanf("%31s",typeString);
		 }
	}while(strlen(typeString)>=31);
	getchar();
}

void CreateData()
{
	char Id[32];
	char Email[32];

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
	printf("Input your Id : ");
	scanf("%31s%*c",Id);
	Blockbufferflow(Id);
	SearchById(Id);
}

char* InputToRemove(char* pId)
{
	printf("Input \"id\" to delete : ");
	scanf("%31s%*c",pId);
	Blockbufferflow(pId);
	return pId;
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
	char Id[32];

	USERDATA* pPrev=NULL;
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
				InputToRemove(Id);
				if(SearchToRemove(&pPrev,Id) != NULL)
					RemoveNode(pPrev);
				break;

			default:
				ReleasesList();
				break;

		}
		getchar();

	}

}
