#include "../includes.h"
#include "../cpu.h"

void rts(void) {
	REGISTERS.PC = REGISTERS.SP;
	REGISTERS.SP += 2;
}
