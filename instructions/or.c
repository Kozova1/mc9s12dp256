#include "../cpu.h"
#include "../set.h"

void oraa(Memory mem) {
	unset('v');
	(REGISTERS.A) ? unset('z') : set('z');
	(REGISTERS.A & 0x80) ? set('n') : unset('n');
	if (isimm(mem)) {
		REGISTERS.A |= mem.imm;
	} else {
		REGISTERS.A |= *(MMAP.MEMORY + mem.pos);
	}
}

void orab(Memory mem) {
	unset('v');
	(REGISTERS.B) ? unset('z') : set('z');
	(REGISTERS.B & 0x80) ? set('n') : unset('n');
	if (isimm(mem)) {
		REGISTERS.B |= mem.imm;
	} else {
		REGISTERS.B |= *(MMAP.MEMORY + mem.pos);
	}
}

void orcc(Memory mem) {
	if (isimm(mem)) {
		REGISTERS.CCR |= mem.imm;
	} else {
		REGISTERS.CCR |= *(MMAP.MEMORY + mem.pos);
	}
}
