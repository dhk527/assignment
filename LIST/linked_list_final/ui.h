#ifndef UI_H
#define UI_H

typedef enum MENU {EXIT, NEW, SEARCH, PRINT, REMOVE} MENU;

void Blockbufferflow(char* );
void CreateData();
void InputToSearch();
char* InputToRemove(char*); 
extern MENU Printmenu();
void EventLoop();

#endif

