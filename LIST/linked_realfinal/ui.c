#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"
#include "singleList.h"

void SetData(char* data)
{
	scanf("%s",data);
	while(strlen(data)>32)
	{
		printf("do not over 32 byte, retype : ");
		scanf("%s",data);
	}
		
}


void CreateData()
{
	char Id[32];
	char Email[32];

	printf("\"Id\": ");
	SetData(Id);

	printf("\"Email\": ");
	SetData(Email);

	AddNewNode(Id, Email);
}


void InputToSearch()
{
	char Id[32];
	puts("Input your Id");
	SetData(Id);
	SearchById(Id);
}

void InputToRemove()
{
	char Id[32];
	puts("Input \"id\" to delete ");
	SetData(Id);
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
