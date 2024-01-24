#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct USERDATA //
{
	char Id[32];
	char Email[64];

	struct USERDATA* pNext; // struct USERDATA*로 선언한 이유는 아직 typedef 형 재선언이 완료되지 않음.
} USERDATA;

USERDATA* g_pHeadNode = NULL; // struct USERDATA* pNext와 동일 자기참조 구조체 
							 
void AddNewNode(const char* pszId, const char* pszEmail) //const -> read 
{
	USERDATA* pNewNode = (USERDATA*)malloc(sizeof(USERDATA));
	strcpy(pNewNode->Id, pszId); // 배열, deep copy
	strcpy(pNewNode->Email, pszEmail);//보안에 취약, scanf_s로 크기제한 권장. 
	pNewNode->pNext = NULL;

	// 조건문 NewNode가 head가 가리키는 곳에 추가 시, g_pHeadNode에 node가 있는지 없는지. 확인
	if(g_pHeadNode == NULL) // node가 없다면 바로 추가
		g_pHeadNode = pNewNode;
	else // node가 이미 있다면 어떻게 해야할까?
	{ // stack head에 node를 추가 시
		pNewNode->pNext=g_pHeadNode; //새 노드는 g_pHeadnode가 가리키는 주소를 가리켜야, 데이터 유실 방지
		g_pHeadNode = pNewNode; // g_pHeadNode는 새 node를 가리켜야 연결 완료.
	}
}

void ReleasesList() // free 언제? 백업이 완료된 이후 
{
	USERDATA* pTmp = g_pHeadNode;
	USERDATA* pDelete;
	while (pTmp != NULL)
	{
		pDelete = pTmp; // pTmp는 pNext를 가리켜야하는데, 가리킬때 free를 하게 되면 데이터 유실, 이를 방지하기 위해 pDelete를 통해 overwrite방지

		printf("pDelete : [%p] %s, %s [%p]\n",
				pDelete, pDelete->Id, pDelete->Email, pDelete->pNext);

		pTmp = pTmp -> pNext; //pDelete가 가리키고 있었고, pTmp는 그다음 node를 가리키게 하여  overwrite되서 다음 Head를 가리킴.
		free(pDelete); //모두 다 잘 가리켰으면 free!
	}

	g_pHeadNode = NULL;
}

void UserData()
{
	AddNewNode("dhk","dhk@waric.co.kr");
	AddNewNode("jhl","jhl@waric.co.kr");
	AddNewNode("ebj","ebj@waric.co.kr");// 출력 시 가장 먼저 출력됨. head쪽에 data추가하기 때문.
}

void PrintList()
{
	USERDATA* pTmp=g_pHeadNode;
	while (pTmp != NULL)
	{
		printf("[%p] %s, %s [%p]\n",
				pTmp, pTmp->Id,	pTmp->Email, pTmp->pNext);

		pTmp = pTmp->pNext; // 다음 list 연결 중요 부분!
	}
}

int main()
{
	int b=sizeof(USERDATA*);
	int c=sizeof(USERDATA);
printf("%d\n",b);
printf("%d\n",c);
putchar('\n');
	UserData();
	PrintList();
	ReleasesList();
	return 0;
}
