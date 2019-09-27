#include "../cpu.h"
#include "../set.h"

void sec(void) {
	set('c');
}

void sei(void) {
	set('i');
}

void sev(void) {
	set('v');
}

void andcc(uint8_t val) {
	REGISTERS.CCR &= val;
}
