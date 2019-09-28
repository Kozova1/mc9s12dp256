#include "../includes.h"
#include "../cpu.h"
#include "../set.h"

void rol(Memory mem) {
	uint8_t _mem = *(MMAP.MEMORY + mem.pos);
	(_mem & 0x80) ? set('v') : unset('v');
	(_mem & 0x80) ? set('c') : unset('c');
	(_mem & 0x40) ? set('n') : unset('n');
	(_mem) ? unset('z') : set('z');
	*(MMAP.MEMORY + mem.pos) = (_mem << 1) + ((_mem & 0x80) ? 1 : 0);
}

void ror(Memory mem) {
	uint8_t _mem = *(MMAP.MEMORY + mem.pos);
	(_mem & 0x01) ? set('v') : unset('v');
	(_mem & 0x01) ? set('c') : unset('c');
	(_mem & 0x01) ? set('n') : unset('n');
	(_mem) ? unset('z') : set('z');
	*(MMAP.MEMORY + mem.pos) = (_mem >> 1) + ((_mem & 0x01) ? 0x80 : 0);
}
