#include "../includes.h"
#include "../cpu.h"

void debug(void) {
	setlocale(LC_ALL, "");
	initscr();
	cbreak();
	noecho();
	WINDOW *win = newwin(20, 30, 5, 10);
}
