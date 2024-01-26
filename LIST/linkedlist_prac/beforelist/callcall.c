#include <stdio.h>

typedef struct USERDATA
{
	char szName[32];
	char szPhone[32];

	struct USERDATA* pNext; 
					
}USERDATA;

int main(void)
{
	USERDATA userList[4] ={
		{"김씨", "010-3032-3211",NULL},
		{"이씨", "123=3142-1312",NULL}, 
		{"조씨", "444-9122-1312",NULL}, 
		{"윤씨", "334-7112-1312",NULL}
	};
	
	USERDATA* pUser=NULL;

	userList[0].pNext=&userList[1]; 
	userList[1].pNext=&userList[2]; 
	userList[2].pNext=&userList[3]; 
	userList[3].pNext=NULL;

	pUser = &userList[0];
	while(pUser != NULL)
	{
		printf("%s, %s\n", pUser->szName,pUser->szPhone);
		pUser=pUser->pNext;
	}

	return 0;
}
