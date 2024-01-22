#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct USERDATA
{
	char Id[32];
	char Email[64];

	struct USERDATA* pNext;
} USERDATA;

USERDATA* g_pHeadNode = NULL; // struct USERDATA* pNext와 똑같으나, typedef를 이용했다. 자기참조 구조체임. 

void AddNewNode(const char* pszId, const char* pszEmail) // scr로 쓸 부분인데 const를 써서 read-only로 만들어 에러 방지
{
	USERDATA* pNewNode = (USERDATA*)malloc(sizeof(USERDATA));
	strcpy(pNewNode->Id, pszId); // deep copy해야됌. 배열이니까.
	strcpy(pNewNode->Email, pszEmail);// strcpy_s같이 보안이 필요할땐 sizeof등으로 크기를 제한시켜야함.
	pNewNode->pNext = NULL;

	if(g_pHeadNode == NULL) // node가 없다면 바로 추가
		g_pHeadNode = pNewNode;
	else // node가 이미 있다면 어떻게 해야할까?
	{
		pNewNode->pNext=g_pHeadNode; // node가 있다면? 새 노드는 g_pHeadnode가 가리키는 주소를 알아야 데이터 유실을 방지
		g_pHeadNode = pNewNode; // g_pHeadNode는 새 node를 가리키겠지.
	}
}

void ReleasesList()
{
	USERDATA* pTmp = g_pHeadNode;
	USERDATA* pDelete;
	while (pTmp != NULL)
	{
		pDelete = pTmp;
		
		printf("pDelete : [%p] %s, %s [%p]\n",
				pDelete, pDelete->Id, pDelete->Email, pDelete->pNext);
		
		pTmp = pTmp -> pNext; //pTmp는 overwrite되서 다음 Head를 가리킴.
		free(pDelete); // pDelete는 지금 point는 살아있죠? 
	}

	g_pHeadNode = NULL;
}


int main()
{
	AddNewNode("dhk","dhk@waric.co.kr");
	AddNewNode("jhl","jhl@waric.co.kr");
	AddNewNode("ebj","ebj@waric.co.kr");

	USERDATA* pTmp=g_pHeadNode;
	while (pTmp != NULL)
	{
		printf("[%p] %s, %s [%p]\n",
				pTmp, pTmp->Id,	pTmp->Email, pTmp->pNext);

		pTmp = pTmp->pNext; // 다음 list 연결!
	}

	ReleasesList();
	return 0;
}
