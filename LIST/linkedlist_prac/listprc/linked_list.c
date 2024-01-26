#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "AddNewData.h"

//void AddNewData();

typedef struct USERDATA
{
	char id[32];
	char email[64];

	struct USERDATA* pNext;
} USERDATA;

void LoadList()
{
	FILE* fp=NULL;
	fopen("UserList.txt","r");
	if(fp==NULL)
		puts("failed to open UserList");

	USERDATA user = { 0 };
	while(fread(&user, sizeof(USERDATA), 1, fp) > 0)
	{
		printf("%s, %s\n",
				user.id, user.email);
		memset(&user, 0, sizeof(USERDATA)); // calloc으로 해도 됨.
	}
	fclose(fp);
}

/*
typedef enum MY_MENU { EXIT, NEW, SEARCH, PRINT, REMOVE } MY_MENU;

MY_MENU PrintMenu()
{
	MY_MENU input = 0;

	system("clear");
	printf("[w]NEW\t[2]Search\t[3]Print\t[4]Remove\t[0]Exit\n");
	scanf("%d",&input);
	return input;
}
*/

int main()
{
	/*
	MY_MENU menu = 0;
	while ((menu = PrintMenu()) != 0)
	{
		switch (menu)
		{
			case NEW;
			AddNewData();
			break;
			
			case SEARCH;
			break;
			
			case PRINT;
			break;

			case REMOVE;
			break;
			
			default;
			break;
		}
	}
	*/


	USERDATA UserList[3]={
		{"dhk","dhk@waric",NULL},
		{"jhl","jhl@waric",NULL},
		{"ebj","ebj@waric",NULL}
	};

	UserList[0].pNext=&UserList[1];
	UserList[1].pNext=&UserList[2];
	UserList[2].pNext=&UserList[3];

	USERDATA* pUser = &UserList[0];//자료구조에 대한 가시성 확보
	while ( pUser != NULL)// tail node 이후에 탈출해야함.
	{
		printf("[%p] %s, %s, [next:%p]\n",
				pUser,
				pUser->id,
				pUser->email,
				pUser->pNext);
		pUser=pUser->pNext; // 다음 list로 연결! 제일 마지막에 기술
	}
//'void* hi;

//	free(hi);
		

//	LoadList();
	
	return 0;
}
