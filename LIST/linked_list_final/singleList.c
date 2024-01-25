#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "singleList.h"

void AddNewNode(const char* pszId, const char* pszEmail) //const -> read-only 
{
	USERDATA* pNewNode = (USERDATA*)malloc(sizeof(USERDATA));
	strcpy(pNewNode->Id, pszId); // 배열, deep copy
	strcpy(pNewNode->Email, pszEmail);
	pNewNode->pNext = NULL;

	if(g_pHeadNode == NULL) 
		g_pHeadNode = pNewNode;
	else 
	{ 
		pNewNode->pNext=g_pHeadNode;// g_pHeadNode주소는 NewNode의 자기 참조 구조체가 assign 
		g_pHeadNode = pNewNode; // 새로 생긴 node의 주소는 g_pHeadNode가 가리킴
	}
}

USERDATA* SearchById(const char* pszId)//record 검색  
{
	USERDATA* pTmp=g_pHeadNode;
	while (pTmp != NULL)
	{
		if(strcmp(pTmp->Id,pszId) == 0)
		{
			printf("\"%s\": Found\n", pszId);
			return pTmp;
		}

		pTmp = pTmp->pNext;
	}
	printf("\"%s\": Not found\n", pszId);
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
	printf("\n End of Record \n");
}

USERDATA* SearchToRemove(USERDATA** ppPrev, const char* pszId)//Search와 비슷하나 *pPrev를 알아야함.
{
	USERDATA* pCurrent=g_pHeadNode;
	USERDATA* pPrev = NULL;
	while (pCurrent != NULL)
	{
		if(strcmp(pCurrent->Id,pszId) == 0)
		{
			*ppPrev = pPrev;//pRemoveNode를 가리키는 pointer
			return pCurrent;
		}
		pPrev = pCurrent;
		pCurrent = pCurrent->pNext;//찾을 때까지 g_pheadnode부터
	}
	printf("\"%s\": Not found", pszId);
	getchar();
	return 0;
}

void RemoveNode(USERDATA* pPrev)
{
	USERDATA* pRemove = NULL;
	if (pPrev == NULL)// case1 : g_pHeadNode만 있고 pPrevNode가 없을 때, 
	{
		if(g_pHeadNode == NULL) // 조건문으로 인해 사실 필요없는 문장?
			return; 
		else
		{
			pRemove = g_pHeadNode;
			g_pHeadNode=pRemove->pNext;
			printf("RemoveNode(): %s\n\n", pRemove->Id);
			free(pRemove);
			getchar();
		}
		return;
	}
	pRemove=pPrev->pNext;// case2 : pPrevNode가 있을 때.
	pPrev->pNext=pRemove->pNext;//중간 삭제 pNext 이어야함.
	free(pRemove); 
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

