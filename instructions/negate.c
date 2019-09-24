#include "../cpu.h"
#include "../set.h"

void neg(uint16_t pos) {
	uint8_t _mem = *(MMAP.MEMORY + pos);
	(_mem & 0x80) ? set('n') : unset('n');
	(_mem & 0xFF) ? unset('z') : set('z');
	if (!(*(MMAP.MEMORY + pos) & 0x80)) {
		*(MMAP.MEMORY + pos) |= 0x80;
	} else {
		*(MMAP.MEMORY + pos) &= 0x7F;
	}
}

void nega(void) {
	uint8_t _rega = REGISTERS.A;
	(_rega & 0x80) ? set('n') : unset('n');
	(_rega & 0xFF) ? unset('z') : set('z');
	// is V overflow even possible here? same for C
	if (!(REGISTERS.A & 0x80)) {
		REGISTERS.A |= 0x80;
	} else {
		REGISTERS.A &= 0x7F;
	}
}

void negb(void) {
	uint8_t _regb = REGISTERS.B;
	(_regb & 0x80) ? set('n') : unset('n');
	(_regb & 0xFF) ? unset('z') : set('z');
	// is V overflow even possible here? same for C
	if (!(REGISTERS.B & 0x80)) {
		REGISTERS.B |= 0x80;
	} else {
		REGISTERS.B &= 0x7F;
	}
}
