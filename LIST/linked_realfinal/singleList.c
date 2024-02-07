#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "singleList.h"

USERDATA* g_pHeadNode=NULL;

void AddNewNode(const char* pszId, const char* pszEmail) //const -> read-only 
{
	USERDATA* pNewNode = (USERDATA*)malloc(sizeof(USERDATA));
	strcpy(pNewNode->Id, pszId); // 배열, deep copy
	strcpy(pNewNode->Email, pszEmail);
	pNewNode->pNext = NULL;

	pNewNode->pNext=g_pHeadNode;
	g_pHeadNode = pNewNode; // 새로 생긴 node의 주소는 g_pHeadNode가 가리킴
}

USERDATA* SearchById(const char* pszId)//record 검색  
{
	USERDATA* pTmp=g_pHeadNode;
	while (pTmp != NULL)
	{
		if(strcmp(pTmp->Id,pszId) == 0)
		{
			printf("\"%s\": Found", pszId);
			return pTmp;
		}

		pTmp = pTmp->pNext;
	}
	printf("\"%s\": Not found", pszId);
	return 0;
}

void PrintList()//record된 data 확인
{
	printf("\nData Table Record\n");
	USERDATA* pTmp=g_pHeadNode;
	while (pTmp != NULL)
	{
		printf("CurListAddr : [%p] Id: %s email: %s NextListAddr[%p]\n",
				pTmp, pTmp->Id,	pTmp->Email, pTmp->pNext);

		pTmp = pTmp->pNext;
	}
	printf("\n End of Record");
}

void RemoveNode(const char* pszId)
{
	USERDATA* pCurrent=g_pHeadNode;
	USERDATA* pPrev = NULL; // 이전 데이터를 가리키는 포인터 변수 선언 및 초기화.
	while (pCurrent != NULL) // 데이터가 없다면 탐색을 종료
	{
		if(strcmp(pCurrent->Id,pszId) == 0) // 지우고 싶은 데이터 중 Id를 입력하여 탐색
		{
			if (pPrev == NULL) // case1: 이전 노드가 없을 때, 삭제 방법 
			{
				g_pHeadNode=pCurrent->pNext;
				free(pCurrent);
				pCurrent=NULL;
				printf("RemoveNode(): %s", pszId);
				return;
			}
			else		  // case2: 이전 노드가 있을 때, 삭제 방법
			{
				pPrev->pNext=pCurrent->pNext;
				free(pCurrent);
				pCurrent=NULL;
				printf("RemoveNode(): %s", pszId);
				return;
			}
		}
		pPrev = pCurrent;
		pCurrent = pCurrent->pNext;//모든 데이터를 탐색
	}
	printf("\n\"%s\": Not found", pszId);
}

void ReleasesList() // backup & free
{
	USERDATA* pTmp = g_pHeadNode;
	USERDATA* pDelete;
	while (pTmp != NULL)
	{
		pDelete = pTmp; 

		printf("pDelete : [%p] %s, %s [%p]\n",
				pDelete, pDelete->Id, pDelete->Email, pDelete->pNext);

		pTmp = pTmp -> pNext; 
		free(pDelete); 
	}

	g_pHeadNode = NULL;
}

