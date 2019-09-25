#include "../includes.h"
#include "../cpu.h"

/* TODO -> implement ncurses based UI for debugging the
 * emulator. Needs to show the Registers, and somehow
 * a part of the normal memory.
 */ 

void debug(void) {
	setlocale(LC_ALL, "");
	initscr();
	cbreak();
	noecho();
	//WINDOW *win = newwin(20, 30, 5, 10);
}
