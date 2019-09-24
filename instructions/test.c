#include "../cpu.h"
#include "../set.h"

void tst(uint16_t pos) {
	unset('c');
	unset('v');
	*(MMAP.MEMORY + pos) ? unset('z') : set('z');
	(*(MMAP.MEMORY + pos) & 0x80) ? set('n') : unset('n');
}

void tsta(void) {
	unset('c');
	unset('v');
	REGISTERS.A ? unset('z') : set('z');
	(REGISTERS.A & 0x80) ? set('n') : unset('n');
}

void tstb(void) {
	unset('c');
	unset('v');
	REGISTERS.B ? unset('z') : set('z');
	(REGISTERS.B & 0x80) ? set('n') : unset('n');
}
