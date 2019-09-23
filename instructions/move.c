#include "../cpu.h"

void movb(uint8_t pos1, uint8_t pos2) {
	// move MMAP.MEMORY from pos1 to pos2
	*(MMAP.MEMORY + pos2) = *(MMAP.MEMORY + pos1);
}

void movw(uint8_t pos1, uint8_t pos2) {
	// move MMAP.MEMORY from pos1 to pos2 but with 2 bytes
	*(MMAP.MEMORY + pos2) 		= *(MMAP.MEMORY + pos1);
	*(MMAP.MEMORY + pos2 + 1) 	= *(MMAP.MEMORY + pos1 + 1);
}
