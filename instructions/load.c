#include "../cpu.h"

void ldaa_mem(uint16_t offset_pos) {
	REGISTERS.A = *(MMAP.MEMORY + offset_pos);
}
void ldaa(uint8_t val) {
	REGISTERS.A = val;
}

void ldab_mem(uint16_t offset_pos) {
	REGISTERS.B = *(MMAP.MEMORY + offset_pos);
}

void ldab(uint8_t val) {
	REGISTERS.B = val;
}

void ldx_mem(uint16_t offset_pos) {
	REGISTERS.X = *(MMAP.MEMORY + offset_pos + 1);
	REGISTERS.X += *(MMAP.MEMORY + offset_pos) << 8;
}

void ldx(uint16_t val) {
	REGISTERS.X = val;
}

void ldy_mem(uint16_t offset_pos) {
	REGISTERS.Y = *(MMAP.MEMORY + offset_pos + 1);
	REGISTERS.Y += *(MMAP.MEMORY + offset_pos) << 8;
}

void ldy(uint16_t val) {
	REGISTERS.Y = val;
}

void ldd_mem(uint16_t offset_pos) {
	REGISTERS.D = *(MMAP.MEMORY + offset_pos + 1);
	REGISTERS.D += *(MMAP.MEMORY + offset_pos) << 8;
}

void ldd(uint16_t val) {
	REGISTERS.D = val;
}

void lds_mem(uint16_t offset_pos) {
	REGISTERS.SP = *(MMAP.MEMORY + offset_pos + 1);
	REGISTERS.SP += *(MMAP.MEMORY + offset_pos) << 8;
}

void lds(uint16_t val) {
	REGISTERS.SP = val;
}
