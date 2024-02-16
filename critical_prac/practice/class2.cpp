class UserData
{
public: // 접근 제어 지시자.
	int age;
	char name[32];

	void print()//cpp name mangling으로 돼서 다른 class 에서 이름이 같아도 유일한 함수로 보임. 
	{			//UserData a,b 라고 해도 print()는 함수는 하나이고 &a, &b의 주소로 남는다~
		printf("%d, %s\n", age, name);
	}
};

int main()
{
	UserData user = { 10, "Hoon" };
	user.Print(); // 굳이 &user 라고 할 필요가 없어진다!
}

