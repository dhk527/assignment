#include <stdio.h>
#include <conio.h>
#include "AddNewData.h"

void AddNewData(void)
{
	puts("AddNewData()" );
	puts("press any key");
	_getch();
}

/*
#include <stdio.h>
#include <ncurses.h>
#include "AddNewData.h"

void AddNewData(void) {
	initscr(); // ncurses 초기화

	printw("AddNewData()\n");
	printw("Press any key\n");

	refresh(); // 변경사항 반영

	getch(); // 사용자 입력 기다리기

	endwin(); // ncurses 종료
}

int main() {
	AddNewData();
	return 0;
}
*/
