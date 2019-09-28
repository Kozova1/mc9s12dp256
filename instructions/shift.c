#include "../cpu.h"
#include "../set.h"

void lsl(Memory mem) {
	uint8_t _a = *(MMAP.MEMORY + mem.pos);
	*(MMAP.MEMORY + mem.pos) = (uint8_t)*(MMAP.MEMORY + mem.pos) << 1;
	_a ? unset('z') : set('z');
	((_a & 0x10) | (_a & 0x08)) ? set('n'), set('v'), set('c') : unset('n'), unset('v'), unset('c');
}

void lsla(void) {
	uint8_t _a = REGISTERS.A;
	REGISTERS.A = (uint8_t)REGISTERS.A << 1;
	_a ? unset('z') : set('z');
	((_a & 0x10) | (_a & 0x08)) ? set('n'), set('v'), set('c'): unset('n'), unset('v'), unset('c');
}

void lslb(void) {
	uint8_t _a = REGISTERS.B;
	REGISTERS.B = (uint8_t)REGISTERS.B << 1;
	_a ? unset('z') : set('z');
	((_a & 0x10) | (_a & 0x08)) ? set('n'), set('v'), set('c') : unset('n'), unset('v'), unset('c');
}

void lsld(void) {
	uint16_t _a = REGISTERS.D;
	REGISTERS.D = (uint8_t)REGISTERS.D << 1;
	_a ? unset('z') : set('z');
	((_a & 0x10) | (_a & 0x08)) ? set('n') : unset('n');
	((_a & 0x10) | (_a & 0x8000)) ? set('c') : unset('c');
	((_a & 0x10) | (_a & 0x08)) ? set('v') : unset('v');
}

void lsr(Memory mem) {
	uint8_t _a = *(MMAP.MEMORY + mem.pos);
	*(MMAP.MEMORY + mem.pos) = (uint8_t)*(MMAP.MEMORY + mem.pos) >> 1;
	_a ? unset('z') : set('z');
	unset('n');
	((_a & 0x10) | (_a & 0x08)) ? set('c'), set('c') : unset('c'), unset('v');
}

void lsra(void) {
	uint8_t _a = REGISTERS.A;
	REGISTERS.A = (uint8_t)REGISTERS.A >> 1;
	_a ? unset('z') : set('z');
	unset('n');
	((_a & 0x10) | (_a & 0x08)) ? set('c'), set('v') : unset('c'), unset('v');
}

void lsrb(void) {
	uint8_t _a = REGISTERS.B;
	REGISTERS.B = (uint8_t)REGISTERS.B >> 1;
	_a ? unset('z') : set('z');
	unset('n');
	((_a & 0x10) | (_a & 0x08)) ? set('c'), set('v') : unset('c'), unset('v');
}

void lsrd(void) {
	uint16_t _a = REGISTERS.D;
	REGISTERS.D = (uint8_t)REGISTERS.D >> 1;
	_a ? unset('z') : set('z');
	unset('n');
	((_a & 0x10) | (_a & 0x08)) ? set('c'), set('v') : unset('c'), unset('v');
}

void asr(Memory mem) {
	uint8_t _a = *(MMAP.MEMORY + mem.pos);
	*(MMAP.MEMORY + mem.pos) = (uint8_t)*(MMAP.MEMORY + mem.pos) >> 1;
	*(MMAP.MEMORY + mem.pos) |= (_a & 0x80);
	(_a & 0x1) ? set('c'), set('v') : unset('c'), unset('v');
	(_a & 0x80) ? set('n') : unset('n');
	_a ? unset('z') : set('z');
}

void asra(void) {
	uint8_t _a = REGISTERS.A;
	REGISTERS.A = (uint8_t) REGISTERS.A >> 1;
	REGISTERS.A |= (_a & 0x80);
	(_a & 0x01) ? set('c'), set('v') : unset('c'), unset('v');
	(_a & 0x80) ? set('n') : unset('n');
	_a ? unset('z') : set('z');
}

void asrb(void) {
	uint8_t _a = REGISTERS.B;
	REGISTERS.B = (uint8_t) REGISTERS.B >> 1;
	REGISTERS.B |= (_a & 0x80);
	(_a & 0x01) ? set('c'), set('v') : unset('c'), unset('v');
	(_a & 0x80) ? set('n') : unset('n');
	_a ? unset('z') : set('z');
}

void asld(void) {
	lsld();
}
