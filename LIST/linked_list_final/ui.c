#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "singleList.h"

void CreateData()
{
	char Id[32];
	char Email[64];

	printf("\"Id\": ");
	scanf("%s",Id);
	printf("\"Email\": ");
	scanf("%s",Email);

	AddNewNode(Id, Email);
}


void InputToSearch()
{
	char Id[32];
	puts("Input your Id");
	scanf("%s",Id);
	SearchById(Id);
	getchar();
}

char* InputToRemove(char* Id)
{
	puts("Input Delete USERDATA");
	scanf("%s",Id);
	return Id;
}

MENU Printmenu()
{
	MENU input=0;

	system("clear");
	printf("[1]NEW\t[2]Search\t[3]Print\t[4]Remove\t[0]Exit\n");
	scanf("%d%*c",(int*)&input);
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

























