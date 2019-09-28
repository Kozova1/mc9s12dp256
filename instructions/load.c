#include "../cpu.h"
#include "../set.h"

void ldaa(Memory mem) {
	if (isimm(mem)) {
		REGISTERS.A = mem.imm;
		unset('v');
		REGISTERS.A ? : set('z');
		(REGISTERS.A & 0x10) ? set('n'): unset('n');
	} else {
		REGISTERS.A = *(MMAP.MEMORY + mem.pos);
		unset('v');
		REGISTERS.A ? : set('z');
		(REGISTERS.A & 0x10) ? set('n'): unset('n');
	}
}

void ldab(Memory mem) {
	if (isimm(mem)) {
		REGISTERS.B = mem.imm;
		unset('v');
		REGISTERS.B ? : set('z');
		(REGISTERS.B & 0x10) ? set('n'): unset('n');
	} else {
		REGISTERS.B = *(MMAP.MEMORY + mem.pos);
		unset('v');
		REGISTERS.B ? : set('z');
		(REGISTERS.B & 0x10) ? set('n'): unset('n');
	}
}

void ldx_mem(uint16_t offset_pos) {
	REGISTERS.X = *(MMAP.MEMORY + offset_pos + 1);
	REGISTERS.X += *(MMAP.MEMORY + offset_pos) << 8;
	unset('v');
	REGISTERS.X ? : set('z');
	(REGISTERS.X & 0x1000) ? set('n'): unset('n');
}

void ldx(Memory mem) {
	if (isimm(mem)) {
		REGISTERS.X = mem.imm_ext;
		unset('v');
		REGISTERS.X ? : set('z');
		(REGISTERS.X & 0x1000) ? set('n'): unset('n');
	} else {
		REGISTERS.X = *(MMAP.MEMORY + mem.pos + 1);
		REGISTERS.X += *(MMAP.MEMORY + mem.pos) << 8;
		unset('v');
		REGISTERS.X ? : set('z');
		(REGISTERS.X & 0x1000) ? set('n'): unset('n');
	}
}

void ldy(Memory mem) {
	if (isimm(mem)) {
		REGISTERS.Y = mem.imm_ext;
		unset('v');
		REGISTERS.Y ? : set('z');
		(REGISTERS.Y & 0x1000) ? set('n'): unset('n');
	} else {
		REGISTERS.Y = *(MMAP.MEMORY + mem.pos + 1);
		REGISTERS.Y += *(MMAP.MEMORY + mem.pos) << 8;
		unset('v');
		REGISTERS.Y ? : set('z');
		(REGISTERS.Y & 0x1000) ? set('n'): unset('n');
	}
}

void ldd(Memory mem) {
	if (isimm(mem)) {
		REGISTERS.D = mem.imm_ext;
		unset('v');
		REGISTERS.D ? : set('z');
		(REGISTERS.D & 0x1000) ? set('n'): unset('n');
	} else {
		REGISTERS.D = *(MMAP.MEMORY + mem.pos + 1);
		REGISTERS.D += *(MMAP.MEMORY + mem.pos) << 8;
		unset('v');
		REGISTERS.D ? : set('z');
		(REGISTERS.D & 0x1000) ? set('n'): unset('n');
	}
}

void lds(Memory mem) {
	if (isimm(mem)) {
		REGISTERS.SP = mem.imm_ext;
		unset('v');
		REGISTERS.SP ? : set('z');
		(REGISTERS.SP & 0x1000) ? set('n'): unset('n');
	} else {
		REGISTERS.SP = *(MMAP.MEMORY + mem.pos + 1);
		REGISTERS.SP += *(MMAP.MEMORY + mem.pos) << 8;
		unset('v');
		REGISTERS.SP ? : set('z');
		(REGISTERS.SP & 0x1000) ? set('n'): unset('n');
	}
}
