#include "../cpu.h"
#include "../set.h"

void staa(uint16_t position) {
	*(MMAP.MEMORY + position) = REGISTERS.A;
	unset('v');
	REGISTERS.A ? unset('z') : set('z');
	(REGISTERS.A & 0x80) ? set('n') : unset('n');
}

void stab(uint16_t position) {
	*(MMAP.MEMORY + position) = REGISTERS.B;
	unset('v');
	REGISTERS.B ? unset('z') : set('z');
	(REGISTERS.B & 0x80) ? set('n') : unset('n');
}

void stx(uint16_t position) {
	*(MMAP.MEMORY + position) = (uint8_t)(REGISTERS.X >> 8);
	*(MMAP.MEMORY + position + 1) = (uint8_t)(REGISTERS.X & 0xFF);
	unset('v');
	REGISTERS.X ? unset('z') : set('z');
	(REGISTERS.X & 0x8000) ? set('n') : unset('n');
}

void sty(uint16_t position) {
	*(MMAP.MEMORY + position) = (uint8_t)(REGISTERS.Y >> 8);
	*(MMAP.MEMORY + position + 1) = (uint8_t)(REGISTERS.Y & 0xFF);
	unset('v');
	REGISTERS.Y ? unset('z') : set('z');
	(REGISTERS.Y & 0x8000) ? set('n') : unset('n');
}

void std(uint16_t position) {
	*(MMAP.MEMORY + position) = REGISTERS.A;
	*(MMAP.MEMORY + position) = REGISTERS.B;
	unset('v');
	REGISTERS.D ? unset('z') : set('z');
	(REGISTERS.D & 0x8000) ? set('n') : unset('n');
}

void sts(uint16_t position) {
	*(MMAP.MEMORY + position) = (uint8_t)(REGISTERS.SP >> 8);
	*(MMAP.MEMORY + position + 1) = (uint8_t)(REGISTERS.SP & 0xFF);
	unset('v');
	REGISTERS.SP ? unset('z') : set('z');
	(REGISTERS.SP & 0x8000) ? set('n') : unset('n');
}
