#include "../cpu.h"

void staa(uint16_t position) {
	*(MMAP.MEMORY + position) = REGISTERS.A;
}

void stab(uint16_t position) {
	*(MMAP.MEMORY + position) = REGISTERS.B;
}

void stx(uint16_t position) {
	*(MMAP.MEMORY + position) = (uint8_t)(REGISTERS.X >> 8);
	*(MMAP.MEMORY + position + 1) = (uint8_t)(REGISTERS.X & 0xFF);
}

void sty(uint16_t position) {
	*(MMAP.MEMORY + position) = (uint8_t)(REGISTERS.Y >> 8);
	*(MMAP.MEMORY + position + 1) = (uint8_t)(REGISTERS.Y & 0xFF);
}

void std(uint16_t position) {
	*(MMAP.MEMORY + position) = REGISTERS.A;
	*(MMAP.MEMORY + position) = REGISTERS.B;
}

void sts(uint16_t position) {
	*(MMAP.MEMORY + position) = (uint8_t)(REGISTERS.SP >> 8);
	*(MMAP.MEMORY + position + 1) = (uint8_t)(REGISTERS.SP & 0xFF);
}
