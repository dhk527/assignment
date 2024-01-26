#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum MENU {NEW, SEARCH, PRINT, REMOVE, EXIT} MENU;

typedef struct USERDATA
{
	char Id[32];
	char Email[64];

	struct USERDATA* pPrev;
	struct USERDATA* pNext; 
} USERDATA;


USERDATA g_HeadNode = { "none", "_Dummy Head node_" }; //int 65335 32767
USERDATA g_TailNode = { "none", "_Dummy tail node_" }; 

void InitList()
{
	g_HeadNode.pNext = &g_TailNode;// 멀티쓰레딩시는 위험.
	g_TailNode.pPrev = &g_HeadNode;
}

void AddNewNode(const char* pszId, const char* pszEmail) 
{
	USERDATA* pNewNode = (USERDATA*)malloc(sizeof(USERDATA));
	strcpy(pNewNode->Id, pszId); 
	strcpy(pNewNode->Email, pszEmail);
	pNewNode->pPrev = NULL;
	pNewNode->pNext = NULL; // pNewNode를 생성 

	USERDATA* pPrevNode = g_TailNode.pPrev; 
	pNewNode->pPrev = g_TailNode.pPrev; // 포인터변수가 아니니 dot을 이용하기  &g_HeadNode를 가리키니 
	// 새로운 간점노드는 pPrev로 연결
	pNewNode->pNext = &g_TailNode;  //pNext가 담는 주소 보여줌.

	pPrevNode->pNext = pNewNode; //추가 노드 연결
	g_TailNode.pPrev = pNewNode; //추가 노드 연결

}

void ReleasesList()
{
	USERDATA* pTmp = g_HeadNode.pNext;
	USERDATA* pDelete;
	while (pTmp != NULL && pTmp !=&g_TailNode)
	{
		pDelete = pTmp; 
		pTmp = pTmp -> pNext; 

		printf("pDelete : [%p] %s, %s [%p]\n",
				pDelete, pDelete->Id, pDelete->Email, pDelete->pNext);

		free(pDelete); 
	}

	g_HeadNode.pNext = NULL;
}

USERDATA* SearchById(const char* pszId)
{
	USERDATA* pTmp = g_HeadNode.pNext;
	while(pTmp != NULL)
	{
		if(strcmp(pTmp->Id, pszId)==0)
		{
			printf("\"%s\": Found\n", pszId);
			return pTmp;
		}
		pTmp = pTmp->pNext;
	}
	printf("\"%s\": Not Found\n", pszId);
	return NULL;
}

void RemoveNode(USERDATA* pRemove)
{
	USERDATA* pPrev = pRemove->pPrev;
	USERDATA* pNext = pRemove->pNext;

	pPrev->pNext = pRemove -> pNext;
	pNext->pPrev = pRemove -> pPrev;

	printf("RemoveNode(): %s\n", pRemove->Id);
	free(pRemove);
}

void InitDummyData()
{
	AddNewNode("dhk","dhk@waric.co.kr");
	AddNewNode("jhl","jhl@waric.co.kr");
	AddNewNode("ebj","ebj@waric.co.kr");
}

void PrintList()
{
	USERDATA* pTmp= &g_HeadNode;
	while (pTmp != NULL)
	{
		printf("[%p] %s, %s [%p]\n",
				pTmp, pTmp->Id,	pTmp->Email, pTmp->pNext);

		pTmp = pTmp->pNext;
	}
	putchar('\n');
	getchar();
}

void PrintListReverse()
{
	USERDATA* pTmp = g_TailNode.pPrev;
	while(pTmp != NULL)
	{
		printf("[%p] %s, %s [%p]\n",
				pTmp, pTmp->Id,	pTmp->Email, pTmp->pNext);

		pTmp = pTmp->pPrev;
	}
	putchar('\n');
}

int IsEmpty()
{
	if(g_HeadNode.pNext == &g_TailNode)
		return 1;

	return 0;
}

void Push(USERDATA* pUser)//현재 tail로 구성되어있는데 push-pop 형태로 구현해보기.
{
	USERDATA* pNewNode = (USERDATA*)malloc(sizeof(USERDATA));
	memcpy(pNewNode, pUser, sizeof(USERDATA));
	pNewNode->pPrev = NULL;
	pNewNode->pNext = NULL; // pNewNode를 생성 

	USERDATA* pNextNode = g_HeadNode.pNext; 
	pNewNode->pPrev = &g_HeadNode; // 포인터변수가 아니니 dot을 이용하기  &g_HeadNode를 가리키니 
	// 새로운 간점노드는 pPrev로 연결
	pNewNode->pNext = g_HeadNode.pNext; //pNext가 담는 주소 보여줌.

	pNextNode->pPrev = pNewNode; //추가 노드 연결
	g_HeadNode.pNext = pNewNode; //추가 노드 연결
}

USERDATA* Pop()// 현재 tail로 구성되있는데 push-pop 형태로 구성해보기
{
	if(IsEmpty())
	{
		puts("Stack : Underflow error.");
		return NULL;
	}

	USERDATA* pPop = g_HeadNode.pNext;
	g_HeadNode.pNext=pPop->pNext;
	pPop->pNext->pPrev=pPop->pPrev;

	return pPop;
}

USERDATA* Dequeue()// 이미 queue 형태니까 tail로 ㅇㅇ
{
	return Pop();
}

void Enqueue(USERDATA* pUser)// 이미 queue 형태인데 
{
	AddNewNode(pUser->Id, pUser->Email);
}
void TestStackAndQueu()
{

	USERDATA user = {"init", "init"};
	Push(&user);
	strcpy(user.Id,"hi");// deep copy, 정수는 그냥 바뀌는데...
	Push(&user);
	strcpy(user.Id, "bye");
	Push(&user);
	PrintList();
	/*
	   Enqueue(&user)
	   strcpy(user.Id,"hi");// deep copy, 정수는 그냥 바뀌는데...
	   Enqueue(&user)
	   strcpy(user.Id,"hi");// deep copy, 정수는 그냥 바뀌는데...
	   Enqueue(&user)
	   strcpy(user.Id,"hi");// deep copy, 정수는 그냥 바뀌는데...

	   for(int i;i<3;i++)
	   {
	   USERDATA* pUser = Dequeue();
	   printf("Pop:%s, %s", pUser->Id, pUser->Email);
	   free(pUser);
	   putchar('\n');
	   }*/

/*	for(int i;i<3;i++)
	{
		USERDATA* pUser = Pop();
		printf("Pop:%s, %s", pUser->Id, pUser->Email);
		free(pUser);
		putchar('\n');
	}
	//PrintList();
	//ReleasesList();

	return 0;*/
}


int main()
{
	InitList();
	USERDATA user = {"init", "init"};
	Push(&user);
	strcpy(user.Id,"hi");// deep copy, 정수는 그냥 바뀌는데...
	Push(&user);
	strcpy(user.Id, "bye");
	Push(&user);
	PrintList();
	/*
	   Enqueue(&user)
	   strcpy(user.Id,"hi");// deep copy, 정수는 그냥 바뀌는데...
	   Enqueue(&user)
	   strcpy(user.Id,"hi");// deep copy, 정수는 그냥 바뀌는데...
	   Enqueue(&user)
	   strcpy(user.Id,"hi");// deep copy, 정수는 그냥 바뀌는데...

	   for(int i;i<3;i++)
	   {
	   USERDATA* pUser = Dequeue();
	   printf("Pop:%s, %s", pUser->Id, pUser->Email);
	   free(pUser);
	   putchar('\n');
	   }*/

	for(int i;i<3;i++)
	{
		USERDATA* pUser = Pop();
		printf("Pop:%s, %s", pUser->Id, pUser->Email);
		free(pUser);
		putchar('\n');
	}
	//PrintList();
	//ReleasesList();

	return 0;

}





