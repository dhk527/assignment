#ifndef singleList_H
#define singleList_H

typedef struct USERDATA
{
	char Id[32];
	char Email[32];

	struct USERDATA* pNext; // 자기참조 구조체 
} USERDATA;

extern USERDATA* g_pHeadNode;

void AddNewNode(const char* pszId, const char* pszEmail);
void ReleasesList(); // backup & free
void PrintList();
USERDATA* SearchById(const char* pszId);      
void RemoveNode(const char* pszId);

#endif
