#include "../cpu.h"
#include "../set.h"

void anda(Memory mem) {
	if (isimm(mem)) {
		REGISTERS.A &= mem.imm;
		unset('v');
		REGISTERS.A ? unset('z') : set('z');
		(REGISTERS.A & 0x80) ? set('n') : unset('n');
	} else {
		REGISTERS.A &= *(MMAP.MEMORY + mem.pos);
		unset('v');
		REGISTERS.A ? unset('z') : set('z');
		(REGISTERS.A & 0x80) ? set('n') : unset('n');
	}
}

void andb(Memory mem) {
	if (isimm(mem)) {
		REGISTERS.B &= mem.imm;
		unset('v');
		REGISTERS.B ? unset('z') : set('z');
		(REGISTERS.B & 0x80) ? set('n') : unset('n');
	} else {
		REGISTERS.B &= *(MMAP.MEMORY + mem.pos);
		unset('v');
		REGISTERS.B ? unset('z') : set('z');
		(REGISTERS.B & 0x80) ? set('n') : unset('n');
	}
}
