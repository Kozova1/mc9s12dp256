#include "../cpu.h"
#include "../set.h"

void oraa(uint8_t to_or) {
	unset('v');
	(REGISTERS.A) ? unset('z') : set('z');
	(REGISTERS.A & 0x80) ? set('n') : unset('n');
	REGISTERS.A |= to_or;
}

void orab(uint8_t to_or) {
	unset('v');
	(REGISTERS.B) ? unset('z') : set('z');
	(REGISTERS.B & 0x80) ? set('n') : unset('n');
	REGISTERS.B |= to_or;
}

void orcc(uint8_t to_or) {
	unset('v');
	(REGISTERS.CCR) ? unset('z') : set('z');
	(REGISTERS.CCR & 0x80) ? set('n') : unset('n');
	REGISTERS.CCR |= to_or;
}
