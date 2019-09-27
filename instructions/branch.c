#include "../includes.h"
#include "../cpu.h"

void bcc(uint16_t pos) {
	if (!(REGISTERS.CCR & 0x1)) {
		REGISTERS.PC += (2 + pos);
	}
}

void bcs(uint16_t pos) {
	if (REGISTERS.CCR & 0x1) {
		REGISTERS.PC += (2 + pos);
	}
}

void beq(uint16_t pos) {
	if (REGISTERS.CCR & 0x4) {
		REGISTERS.PC += (2 + pos);
	}
}

void bgt(uint16_t pos) {
	if (!((REGISTERS.CCR & 0x4) | ((REGISTERS.CCR & 0x8) ^ (REGISTERS.CCR & 0x2)))) {
		REGISTERS.PC += (2 + pos);
	}
}

void bhi(uint16_t pos) {
	if ((REGISTERS.CCR & 0x4) | (REGISTERS.CCR & 0x1)) {
		REGISTERS.PC += (2 + pos);
	}
}

void bhs(uint16_t pos) {
	bcc(pos);
}

void ble(uint16_t pos) {
	if ((REGISTERS.CCR & 0x4) | ((REGISTERS.CCR & 0x8) ^ (REGISTERS.CCR & 0x2))) {
		REGISTERS.PC += (2 + pos);
	}
}

void blo(uint16_t pos) {
	bcs(pos);
}

void bls(uint16_t pos) {
	if ((REGISTERS.CCR & 0x1)) {
		REGISTERS.PC += (2 + pos);
	}
}

void blt(uint16_t pos) {
	if ((REGISTERS.CCR & 0x8) ^ (REGISTERS.CCR & 0x2)) {
		REGISTERS.PC += (2 + pos);
	}
}

void bmi(uint16_t pos) {
	if (REGISTERS.CCR & 0x8) {
		REGISTERS.PC += (2 + pos);
	}
}

void bne(uint16_t pos) {
	if (!(REGISTERS.CCR & 0x4)) {
		REGISTERS.PC += (2 + pos);
	}
}

void bpl(uint16_t pos) {
	if (!(REGISTERS.CCR & 0x8)) {
		REGISTERS.PC += (2 + pos);
	}
}

void bra(uint16_t pos) {
	REGISTERS.PC += (2 + pos);
}

void brn(uint16_t pos) {

}

// TODO -> brset, brclr, bsr
void bvc(uint16_t pos) {
	if (!(REGISTERS.CCR & 0x2)) {
		REGISTERS.PC += (2 + pos);
	}
}

void bvs(uint16_t pos) {
	if (REGISTERS.CCR & 0x2) {
		REGISTERS.PC += (2 + pos);
	}
}

void jmp(uint16_t pos) {
	REGISTERS.PC = pos;
}

//TODO -> Long Branch instructions
