#include "../cpu.h"
#include "../set.h"

void oraa(Memory mem) {
	unset('v');
	(REGISTERS.A) ? unset('z') : set('z');
	(REGISTERS.A & 0x80) ? set('n') : unset('n');
	if (isimm(mem) == 1) {
		REGISTERS.A |= mem.imm;
	} else if (isimm(mem) == 0) {
		REGISTERS.A |= *(MMAP.MEMORY + mem.pos);
	}
}

void orab(Memory mem) {
	unset('v');
	(REGISTERS.B) ? unset('z') : set('z');
	(REGISTERS.B & 0x80) ? set('n') : unset('n');
	if (isimm(mem) == 1) {
		REGISTERS.B |= mem.imm;
	} else if (isimm(mem) == 0){
		REGISTERS.B |= *(MMAP.MEMORY + mem.pos);
	}
}

void orcc(Memory mem) {
	if (isimm(mem) == 1) {
		REGISTERS.CCR |= mem.imm;
	} else if (isimm(mem) == 0){
		REGISTERS.CCR |= *(MMAP.MEMORY + mem.pos);
	}
}
