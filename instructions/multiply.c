#include "../cpu.h"
#include "../set.h"

void mul() {
	int _a = (int)(REGISTERS.A * REGISTERS.B);
	REGISTERS.D = (uint16_t)_a;
	(_a > 0xFFFF) ? set('c') : unset('c');
}
