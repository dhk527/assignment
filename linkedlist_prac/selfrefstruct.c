#include <stdio.h>

typedef struct USERDATA
{
	char szName[32];
	char szPhone[32];

	struct USERDATA* pNext; // 자기참조 구조체 (이게 연결리스트의 핵심)
							// 어라 왜 USERDATA* pNext; 가 아닐까? 
							//아직 형 재선언안했으니까 (procedral 하니까...)
}USERDATA;

int main(void)
{
	USERDATA user = {"김씨", "010-3032-3211",NULL};
	USERDATA newuser = {"이씨", "123=312-12312",NULL}; // 원래는 malloc써서 동적할당으로 한다는데 일단 stack으로 하면 공간을 많이 차지하니까.
	printf("user : %s, %s, %p \n" , user.szName, user.szPhone, user.pNext);
	printf("user : %s, %s, %p \n" , newuser.szName, newuser.szPhone, newuser.pNext); 

	user.pNext=&newuser; // 자기 참조 구조체와 더불어 핵심이 되는 녀석!

	printf("user : %s, %s, %p \n" , user.szName, user.szPhone, user.pNext);
	printf("user : %s, %s, %p \n" , newuser.szName, newuser.szPhone, newuser.pNext); 

	printf("자 연결 리스트 해보니까? user에서 이어진걸 볼까?\n");
	printf("user.pNext의 리스트는? : %s, %s\n", user.pNext->szName, user.pNext->szPhone);

	return 0;
}
