#ifndef singleList_H
#define singleList_H


typedef struct USERDATA
{
	char Id[32];
	char Email[64];

	struct USERDATA* pNext; 
} USERDATA;

extern USERDATA* g_pHeadNode; //자기참조 구조체 

void AddNewNode(const char* pszId, const char* pszEmail);
void ReleasesList(); // backup & free
void PrintList();
USERDATA* SearchById(const char* pszId);//UI      
USERDATA* SearchToRemove(USERDATA **ppPrev, const char* pszId);//UI   
void RemoveNode(USERDATA* pPrev);          

#endif
