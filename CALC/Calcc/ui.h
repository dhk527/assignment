#ifndef UI_H
#define UI_H

typedef enum MENU {EXIT, ADD, SUB, DIV, MUL} MENU;

extern void SetData(double*, double*);
extern MENU Printmenu();
extern void EventLoop();
#endif

