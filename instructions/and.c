#include "../cpu.h"
#include "../set.h"

void anda(uint8_t val) {
	REGISTERS.A &= val;
	unset('v');
	REGISTERS.A ? unset('z') : set('z');
	(REGISTERS.A & 0x80) ? set('n') : unset('n');
}

void anda_mem(uint16_t pos) {
	REGISTERS.A &= *(MMAP.MEMORY + pos);
	unset('v');
	REGISTERS.A ? unset('z') : set('z');
	(REGISTERS.A & 0x80) ? set('n') : unset('n');
}

void andb(uint8_t val) {
	REGISTERS.B &= val;
	unset('v');
	REGISTERS.B ? unset('z') : set('z');
	(REGISTERS.B & 0x80) ? set('n') : unset('n');
}

void andb_mem(uint16_t pos) {
	REGISTERS.B &= *(MMAP.MEMORY + pos);
	unset('v');
	REGISTERS.B ? unset('z') : set('z');
	(REGISTERS.B & 0x80) ? set('n') : unset('n');
}
