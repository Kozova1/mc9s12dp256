#include "../cpu.h"
#include "../set.h"

void ldaa_mem(uint16_t offset_pos) {
	REGISTERS.A = *(MMAP.MEMORY + offset_pos);
	unset('v');
	REGISTERS.A ? : set('z');
	(REGISTERS.A & 0x10) ? set('n'): unset('n');
}

void ldaa(uint8_t val) {
	REGISTERS.A = val;
	unset('v');
	REGISTERS.A ? : set('z');
	(REGISTERS.A & 0x10) ? set('n'): unset('n');
}

void ldab_mem(uint16_t offset_pos) {
	REGISTERS.B = *(MMAP.MEMORY + offset_pos);
	unset('v');
	REGISTERS.B ? : set('z');
	(REGISTERS.B & 0x10) ? set('n'): unset('n');
}

void ldab(uint8_t val) {
	REGISTERS.B = val;
	unset('v');
	REGISTERS.B ? : set('z');
	(REGISTERS.B & 0x10) ? set('n'): unset('n');
}

void ldx_mem(uint16_t offset_pos) {
	REGISTERS.X = *(MMAP.MEMORY + offset_pos + 1);
	REGISTERS.X += *(MMAP.MEMORY + offset_pos) << 8;
	unset('v');
	REGISTERS.X ? : set('z');
	(REGISTERS.X & 0x1000) ? set('n'): unset('n');
}

void ldx(uint16_t val) {
	REGISTERS.X = val;
	unset('v');
	REGISTERS.X ? : set('z');
	(REGISTERS.X & 0x1000) ? set('n'): unset('n');
}

void ldy_mem(uint16_t offset_pos) {
	REGISTERS.Y = *(MMAP.MEMORY + offset_pos + 1);
	REGISTERS.Y += *(MMAP.MEMORY + offset_pos) << 8;
	unset('v');
	REGISTERS.Y ? : set('z');
	(REGISTERS.Y & 0x1000) ? set('n'): unset('n');
}

void ldy(uint16_t val) {
	REGISTERS.Y = val;
	unset('v');
	REGISTERS.Y ? : set('z');
	(REGISTERS.Y & 0x1000) ? set('n'): unset('n');
}

void ldd_mem(uint16_t offset_pos) {
	REGISTERS.D = *(MMAP.MEMORY + offset_pos + 1);
	REGISTERS.D += *(MMAP.MEMORY + offset_pos) << 8;
	unset('v');
	REGISTERS.D ? : set('z');
	(REGISTERS.D & 0x1000) ? set('n'): unset('n');
}

void ldd(uint16_t val) {
	REGISTERS.D = val;
	unset('v');
	REGISTERS.D ? : set('z');
	(REGISTERS.D & 0x1000) ? set('n'): unset('n');
}

void lds_mem(uint16_t offset_pos) {
	REGISTERS.SP = *(MMAP.MEMORY + offset_pos + 1);
	REGISTERS.SP += *(MMAP.MEMORY + offset_pos) << 8;
	unset('v');
	REGISTERS.SP ? : set('z');
	(REGISTERS.SP & 0x1000) ? set('n'): unset('n');
}

void lds(uint16_t val) {
	REGISTERS.SP = val;
	unset('v');
	REGISTERS.SP ? : set('z');
	(REGISTERS.SP & 0x1000) ? set('n'): unset('n');
}
