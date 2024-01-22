#include <stdio.h>

typedef struct USERDATA
{
	char szName[32];
	char szPhone[32];

	struct USERDATA* pNext; 
					
}USERDATA;

void PrintUserData(USERDATA* pUser)
{
/*	if(pUser==NULL)
		return;
		*/

	printf("[%p]%s, %s pNext:%p\n",pUser,pUser->szName,pUser->szPhone,pUser->pNext);
	//pUser->pNext 자기 참조 pNext중요
	PrintUserData(pUser->pNext); // 함수도 for문 처럼 돌릴 수 있잖아! 이것이 재귀호출
								// 언제까지? 위에 딱 써져있네 if(pUser==NULL) return; 될때까지!
	return;
}

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

	pUser = &userList[0]; //연결 리스트 되는 부분이 굉장히 중요함. 

	/*
	while(pUser != NULL)
	{
		printf("%s, %s\n", pUser->szName,pUser->szPhone);
		pUser=pUser->pNext;
	}
*/ // 재귀 호출 할라면 이 부분을 없애야겠지?
	//대신 이렇게 써봐

	PrintUserData(&userList[0]);




	return 0;
}
