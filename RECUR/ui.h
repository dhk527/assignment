#ifndef UI_H
#define UI_H

typedef enum MENU{EXIT, Operation} MENU;

void SetValue(int*, int*);
void view_value(int*, int*, int*);
MENU Printmenu();
void EventLoop();

#endif
