#ifndef singleList_H
#define singleList_H


typedef struct USERDATA
{
	char Id[32];
	char Email[64];

	struct USERDATA* pNext; // 자기참조 구조체 
} USERDATA;

USERDATA* g_pHeadNode;

void AddNewNode(const char* pszId, const char* pszEmail);
void ReleasesList(); // backup & free
void PrintList();
USERDATA* SearchById(const char* pszId);      

USERDATA* SearchToRemove(USERDATA **ppPrev, const char* pszId);   
void RemoveNode(USERDATA* pPrev);          

#endif
