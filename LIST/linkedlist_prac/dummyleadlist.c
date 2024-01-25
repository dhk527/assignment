#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct USERDATA
{
	char Id[32];
	char Email[64];

	struct USERDATA* pNext; // struct USERDATA*로 선언한 이유는 아직 typedef 형 재선언이 완료되지 않음.
} USERDATA;

//USERDATA* g_HeadNode = NULL; // struct USERDATA* pNext와 동일 자기참조 구조체 
USERDATA g_HeadNode = { "none", "_DummyHead_" }; // 그냥 null하지말고 그냥 잡아버린다

							 
void AddNewNode(const char* pszId, const char* pszEmail) //const -> read 
{
	USERDATA* pNewNode = (USERDATA*)malloc(sizeof(USERDATA));
	strcpy(pNewNode->Id, pszId); // 배열, deep copy
	strcpy(pNewNode->Email, pszEmail);//보안에 취약, scanf_s로 크기제한 권장. 
	pNewNode->pNext = NULL;

	// 조건문 NewNode가 head가 가리키는 곳에 추가 시, g_HeadNode에 node가 있는지 없는지. 확인
//	if(g_HeadNode == NULL) // node가 없다면 바로 추가
//		g_HeadNode = pNewNode; //해당 사항이 없어짐
//	else // node가 이미 있다면 어떻게 해야할까?
//	{ // queue tail node를 추가 시
	USERDATA* pTail=&g_HeadNode;
	while(pTail->pNext != NULL)
		pTail=pTail->pNext;

	pTail->pNext = pNewNode;

}

void ReleasesList() // free 언제? 백업이 완료된 이후 
{
	USERDATA* pTmp = g_HeadNode.pNext;
	USERDATA* pDelete;
	while (pTmp != NULL)
	{
		pDelete = pTmp; // pTmp는 pNext를 가리켜야하는데, 가리킬때 free를 하게 되면 데이터 유실, 이를 방지하기 위해 pDelete를 통해 overwrite방지

		printf("pDelete : [%p] %s, %s [%p]\n",
				pDelete, pDelete->Id, pDelete->Email, pDelete->pNext);

		pTmp = pTmp -> pNext; //pDelete가 가리키고 있었고, pTmp는 그다음 node를 가리키게 하여  overwrite되서 다음 Head를 가리킴.
		free(pDelete); //모두 다 잘 가리켰으면 free!
	}

	g_HeadNode.pNext = NULL;
}

USERDATA* SearchToRemove(const char* pszId)
{
	USERDATA* pPrev = &g_HeadNode;
	while(pPrev->pNext != NULL)
	{
		if(strcmp(pPrev->pNext->Id, pszId)==0)
			return pPrev;
	
		pPrev = pPrev->pNext;
	}
	return NULL;
}

void RemoveNode(USERDATA* pPrev)
{
	USERDATA* pRemove = NULL;

	pRemove = pPrev -> pNext;
	pPrev->pNext = pRemove -> pNext;
	printf("RemoveNode(): %s\n", pRemove->Id);
	free(pRemove);
}



void UserData()
{
	AddNewNode("dhk","dhk@waric.co.kr");
	AddNewNode("jhl","jhl@waric.co.kr");
	AddNewNode("ebj","ebj@waric.co.kr");// 출력 시 가장 먼저 출력됨. head쪽에 data추가하기 때문.
}

void PrintList()
{
	USERDATA* pTmp= &g_HeadNode;
	while (pTmp != NULL)
	{
		printf("[%p] %s, %s [%p]\n",
				pTmp, pTmp->Id,	pTmp->Email, pTmp->pNext);

		pTmp = pTmp->pNext; // 다음 list 연결 중요 부분!
	}
}

int main()
{
	UserData();
	PrintList();
	ReleasesList();
	USERDATA* pPrev=SearchToRemove( "Hoon");
	if(pPrev != NULL)
		RemoveNode(pPrev);
	ReleasesList();
	putchar('\n');
	return 0;
}





