#include "../cpu.h"
void lsl(uint8_t pos) {
	uint8_t _a = *(MMAP.MEMORY + pos) & 1;
	*(MMAP.MEMORY + pos) = *(MMAP.MEMORY + pos) << 1;
	REGISTERS.CCR |= _a;
}

void lsla(void) {
	uint8_t _a = REGISTERS.A & 1;
	REGISTERS.A = REGISTERS.A << 1;
	REGISTERS.CCR |= _a;
}

void lslb(void) {
	uint8_t _a = REGISTERS.B & 1;
	REGISTERS.B = REGISTERS.B << 1;
	REGISTERS.CCR |= _a;
}

void lsld(void) {
	uint8_t _a = (uint8_t) REGISTERS.D & 1;
	REGISTERS.D = REGISTERS.D << 1;
	REGISTERS.CCR |= _a;
}

void lsr(uint8_t pos) {
	uint8_t _a = (*(MMAP.MEMORY + pos) & 0x80) / 0x80;
	*(MMAP.MEMORY + pos) = *(MMAP.MEMORY + pos) >> 1;
	REGISTERS.CCR |= _a;
}

void lsra(void) {
	uint8_t _a = (REGISTERS.A & 0x80) / 0x80;
	REGISTERS.A = REGISTERS.A >> 1;
	REGISTERS.CCR |= _a;
}

void lsrb(void) {
	uint8_t _a = (REGISTERS.B & 0x80) / 0x80;
	REGISTERS.B = REGISTERS.B >> 1;
	REGISTERS.CCR |= _a;
}

void lsrd(void) {
	uint8_t _a = (REGISTERS.D & 0x8000) / 0x8000;
	REGISTERS.D = REGISTERS.D >> 1;
	REGISTERS.CCR |= _a;
}
