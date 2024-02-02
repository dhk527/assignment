#ifndef UI_H
#define UI_H

typedef enum MENU {EXIT, ADD, SUB, DIV, MUL} MENU;

void GetData(double*, double*);
extern MENU Printmenu();
void EventLoop();
#endif

