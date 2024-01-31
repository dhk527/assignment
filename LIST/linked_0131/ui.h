#ifndef UI_H
#define UI_H

typedef enum MENU {EXIT, NEW, SEARCH, PRINT, REMOVE} MENU;

void CreateData();
void InputToSearch();
void InputToRemove(); 
extern MENU Printmenu();
void EventLoop();

#endif

