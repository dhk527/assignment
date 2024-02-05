#include <stdio.h>

typedef struct USERDATA
{
	int age;
	char name[32];
	void(*printData)(struct USERDATA* pUser);
}USERDATA;

void printData(USERDATA* pUser) // USERDATA 의존성이 너무 강력해, USERDATA에 존립의존성이 생김
{
	printf("%d, %s\n", pUser->age, pUser->name);
}

int main()
{
	USERDATA user = { 20, "철수", printData };
	user.printData(&user);// user. 인데 user주소를 몰라...
						//이렇게 인수를 해야 되니... 주소를 알 방법이 없으니 ... 
						//this pointer가 나오는거야.. 그러니까 cpp이 나온거지.
	return 0;
}
// 시점을 잘 파악하자, this pointer
