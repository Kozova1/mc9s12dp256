#include "../cpu.h"
#include "../set.h"

void sba(void) {
	(REGISTERS.A == REGISTERS.B) ? unset('z') : set('z');
	(REGISTERS.B > REGISTERS.A) ? set('n') : unset('n');
	(REGISTERS.B > REGISTERS.A) ? set('v') : unset('v');
	(REGISTERS.B > REGISTERS.A) ? set('c') : unset('c');
	REGISTERS.A = REGISTERS.A - REGISTERS.B;
}

void suba(uint8_t to_sub) {
	(REGISTERS.A == to_sub) ? unset('z') : set('z');
	(to_sub > REGISTERS.A) ? set('n') : unset('n');
	(to_sub > REGISTERS.A) ? set('v') : unset('v');
	(to_sub > REGISTERS.A) ? set('c') : unset('c');
	REGISTERS.A = REGISTERS.A - to_sub;
}

void suba_mem(uint16_t pos) {
	(REGISTERS.A == *(MMAP.MEMORY + pos)) ? unset('z') : set('z');
	(*(MMAP.MEMORY + pos) > REGISTERS.A) ? set('n') : unset('n');
	(*(MMAP.MEMORY + pos) > REGISTERS.A) ? set('v') : unset('v');
	(*(MMAP.MEMORY + pos) > REGISTERS.A) ? set('c') : unset('c');
	REGISTERS.A = REGISTERS.A - *(MMAP.MEMORY + pos);
}

void subb(uint8_t to_sub) {
	(REGISTERS.B == to_sub) ? unset('z') : set('z');
	(to_sub > REGISTERS.B) ? set('n') : unset('n');
	(to_sub > REGISTERS.B) ? set('v') : unset('v');
	(to_sub > REGISTERS.B) ? set('c') : unset('c');
	REGISTERS.B = REGISTERS.B - to_sub;
}

void subb_mem(uint16_t pos) {
	(REGISTERS.B == *(MMAP.MEMORY + pos)) ? unset('z') : set('z');
	(*(MMAP.MEMORY + pos) > REGISTERS.B) ? set('n') : unset('n');
	(*(MMAP.MEMORY + pos) > REGISTERS.B) ? set('v') : unset('v');
	(*(MMAP.MEMORY + pos) > REGISTERS.B) ? set('c') : unset('c');
	REGISTERS.B = REGISTERS.B - *(MMAP.MEMORY + pos);
}

void subd(uint16_t to_sub) {
	(REGISTERS.D == to_sub) ? unset('z') : set('z');
	(to_sub > REGISTERS.D) ? set('n') : unset('n');
	(to_sub > REGISTERS.D) ? set('v') : unset('v');
	(to_sub > REGISTERS.D) ? set('c') : unset('c');
	REGISTERS.D = REGISTERS.D - to_sub;
}
// TODO -> subd_mem
