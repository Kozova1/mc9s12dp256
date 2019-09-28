#include "../cpu.h"
#include "../set.h"

void tst(Memory mem) {
	unset('c');
	unset('v');
	*(MMAP.MEMORY + mem.pos) ? unset('z') : set('z');
	(*(MMAP.MEMORY + mem.pos) & 0x80) ? set('n') : unset('n');
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
