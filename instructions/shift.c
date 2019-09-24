#include "../cpu.h"
#include "../set.h"

void lsl(uint8_t pos) {
	uint8_t _a = *(MMAP.MEMORY + pos);
	*(MMAP.MEMORY + pos) = *(MMAP.MEMORY + pos) << 1;
	_a ? unset('z') : set('z');
	((_a & 0x10) | (_a & 0x08)) ? set('n') : unset('n');
	((_a & 0x10) | (_a & 0x08)) ? set('c') : unset('c');
	((_a & 0x10) | (_a & 0x08)) ? set('v') : unset('v');
}

void lsla(void) {
	uint8_t _a = REGISTERS.A;
	REGISTERS.A = REGISTERS.A << 1;
	_a ? unset('z') : set('z');
	((_a & 0x10) | (_a & 0x08)) ? set('n') : unset('n');
	((_a & 0x10) | (_a & 0x08)) ? set('c') : unset('c');
	((_a & 0x10) | (_a & 0x08)) ? set('v') : unset('v');
}

void lslb(void) {
	uint8_t _a = REGISTERS.B;
	REGISTERS.B = REGISTERS.B << 1;
	_a ? unset('z') : set('z');
	((_a & 0x10) | (_a & 0x08)) ? set('n') : unset('n');
	((_a & 0x10) | (_a & 0x08)) ? set('c') : unset('c');
	((_a & 0x10) | (_a & 0x08)) ? set('v') : unset('v');
}

void lsld(void) {
	uint16_t _a = REGISTERS.D;
	REGISTERS.D = REGISTERS.D << 1;
	_a ? unset('z') : set('z');
	((_a & 0x10) | (_a & 0x08)) ? set('n') : unset('n');
	((_a & 0x10) | (_a & 0x08)) ? set('c') : unset('c');
	((_a & 0x10) | (_a & 0x08)) ? set('v') : unset('v');
}

void lsr(uint8_t pos) {
	uint8_t _a = *(MMAP.MEMORY + pos);
	*(MMAP.MEMORY + pos) = *(MMAP.MEMORY + pos) >> 1;
	_a ? unset('z') : set('z');
	unset('n');
	((_a & 0x10) | (_a & 0x08)) ? set('c') : unset('c');
	((_a & 0x10) | (_a & 0x08)) ? set('v') : unset('v');
}

void lsra(void) {
	uint8_t _a = REGISTERS.A;
	REGISTERS.A = REGISTERS.A >> 1;
	_a ? unset('z') : set('z');
	unset('n');
	((_a & 0x10) | (_a & 0x08)) ? set('c') : unset('c');
	((_a & 0x10) | (_a & 0x08)) ? set('v') : unset('v');
}

void lsrb(void) {
	uint8_t _a = REGISTERS.B;
	REGISTERS.B = REGISTERS.B >> 1;
	_a ? unset('z') : set('z');
	unset('n');
	((_a & 0x10) | (_a & 0x08)) ? set('c') : unset('c');
	((_a & 0x10) | (_a & 0x08)) ? set('v') : unset('v');
}

void lsrd(void) {
	uint16_t _a = REGISTERS.D;
	REGISTERS.D = REGISTERS.D >> 1;
	_a ? unset('z') : set('z');
	unset('n');
	((_a & 0x10) | (_a & 0x08)) ? set('c') : unset('c');
	((_a & 0x10) | (_a & 0x08)) ? set('v') : unset('v');
}
