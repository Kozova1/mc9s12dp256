#include "../cpu.h"
#include "../set.h"

void sba(void) {
	(REGISTERS.A == REGISTERS.B) ? unset('z') : set('z');
	(REGISTERS.B > REGISTERS.A) ? set('n') : unset('n');
	(REGISTERS.B > REGISTERS.A) ? set('v') : unset('v');
	(REGISTERS.B > REGISTERS.A) ? set('c') : unset('c');
	REGISTERS.A = REGISTERS.A - REGISTERS.B;
}

void suba(Memory mem) {
	if (isimm(mem) == 1) {
		(REGISTERS.A == mem.imm) ? unset('z') : set('z');
		(mem.imm > REGISTERS.A) ? set('n'), set('v'), set('c'): unset('n'), unset('v'), unset('c');
		REGISTERS.A = REGISTERS.A - mem.imm;
	} else if (isimm(mem) == 0){
		(REGISTERS.A == *(MMAP.MEMORY + mem.pos)) ? unset('z') : set('z');
		(mem.imm > REGISTERS.A) ? set('n'), set('v'), set('c'): unset('n'), unset('v'), unset('c');
		REGISTERS.A = REGISTERS.A - *(MMAP.MEMORY + mem.pos);
	}
}

void subb(Memory mem) {
	if (isimm(mem) == 1) {
		(REGISTERS.B == mem.imm) ? unset('z') : set('z');
		(mem.imm > REGISTERS.B) ? set('n'), set('v'), set('c'): unset('n'), unset('v'), unset('c');
		REGISTERS.B = REGISTERS.B - mem.imm;
	} else if (isimm(mem) == 0){
		(REGISTERS.B == *(MMAP.MEMORY + mem.pos)) ? unset('z') : set('z');
		(mem.imm > REGISTERS.B) ? set('n'), set('v'), set('c'): unset('n'), unset('v'), unset('c');
		REGISTERS.B = REGISTERS.B - *(MMAP.MEMORY + mem.pos);
	}
}

void subd(Memory mem) {
	if (isimm(mem) == 1) {
		(REGISTERS.D == mem.imm_ext) ? unset('z') : set('z');
		(mem.imm_ext > REGISTERS.D) ? set('n'), set('v'), set('c'): unset('n'), unset('v'), unset('c');
		REGISTERS.D = REGISTERS.D - mem.imm_ext;
	} else if (isimm(mem) == 0){
		(REGISTERS.B == *(MMAP.MEMORY + mem.pos)) ? unset('z') : set('z');
		(mem.imm > REGISTERS.B) ? set('n'), set('v'), set('c'): unset('n'), unset('v'), unset('c');
		REGISTERS.B = REGISTERS.B - *(MMAP.MEMORY + mem.pos);
	}
}
