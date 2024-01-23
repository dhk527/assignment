#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum MENU {EXIT, NEW, SEARCH, PRINT, REMOVE} MENU;

typedef struct USERDATA
{
	char Id[32];
	char Email[64];

	struct USERDATA* pNext; 
} USERDATA;

USERDATA* g_pHeadNode = NULL; //자기참조 구조체 

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
		pNewNode->pNext=g_pHeadNode; 
		g_pHeadNode = pNewNode; 
	}
}

void CreateData()
{
	char Id[32];
	char Email[64];

	printf("\"Id\": ");
	scanf("%s",Id);
	printf("\"Email\": ");
	scanf("%s",Email);
	
	AddNewNode(Id, Email);
	getchar();
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

void PrintList()
{
	printf("\nData Table Filed\n");
	USERDATA* pTmp=g_pHeadNode;
	while (pTmp != NULL)
	{
		printf("[%p] %s, %s [%p]\n",
				pTmp, pTmp->Id,	pTmp->Email, pTmp->pNext);

		pTmp = pTmp->pNext;
	}
	getchar();
}

USERDATA* SearchById(const char* pszId)//UI
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
}

void inputToSearch()
{
	char Id[32];
	puts("Input your Id");
	scanf("%s",Id);
	

USERDATA* SearchToRemove(USERDATA **ppPrev, const char* pszId)//UI
{
	USERDATA* pCurrent=g_pHeadNode;
	USERDATA* pPrev = NULL;
	while (pCurrent != NULL)
	{
		if(strcmp(pCurrent->Id,pszId) == 0)
		{
			*ppPrev = pPrev;
			return pCurrent;
		}
		pPrev = pCurrent;
		pCurrent = pCurrent->pNext;//찾을 때까지 g_pheadnode부터
	}
	printf("\"%s\": Not found\n", pszId);
}

void RemoveNode(USERDATA* pPrev)
{
	USERDATA* pRemove = NULL;
	if (pPrev == NULL)
	{
		if(g_pHeadNode == NULL)
			return; 
		else
		{
			pRemove = g_pHeadNode;
			g_pHeadNode=pRemove->pNext;
			printf("RemoveNode(): %s\n\n", pRemove->Id);
			free(pRemove);
		}
		return;
	}
	pRemove=pPrev->pNext;
	pPrev->pNext=pRemove->pNext;//중간 삭제 pNext 이어야함.
	free(pRemove); 
}

MENU Printmenu()
{
	MENU input=0;

	system("clear");
	printf("[1]NEW\t[2]Search\t[3]Print\t[4]Remove\t[0]Exit\n");
	scanf("%d",(int*)&input);
	return input;
}

int main()
{
	MENU menu=0;

	USERDATA* pPrev=NULL;
	while((menu=Printmenu())!=0)
	{
		switch (menu)
		{
			case NEW:
			CreateData();
			break;

			case SEARCH:
			SearchById(" ");
			getchar();
			break;

			case PRINT:
			PrintList();
			getchar();
			break;

			case REMOVE:
			if(SearchToRemove(&pPrev, " ") != NULL)
				RemoveNode(pPrev);
			getchar();
			break;

			default:
			ReleasesList();
			break;
		
		}

	}

	return 0;
}




























