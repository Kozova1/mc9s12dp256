#include "../cpu.h"
#include "../set.h"

void tab(void) {
	REGISTERS.B = REGISTERS.A;
	unset('v');
	REGISTERS.B ? unset('z') : set('z');
	(REGISTERS.B & 0x80) ? set('n'): unset('n');
}

void tap(void) {
	REGISTERS.CCR = REGISTERS.A;
}

void tba(void) {
	REGISTERS.A = REGISTERS.B;
	unset('v');
	REGISTERS.B ? unset('z') : set('z');
	(REGISTERS.B & 0x80) ? set('n'): unset('n');
}

void tfr(void *from, void *to) {
	if ((to != &REGISTERS.A) && (from != &REGISTERS.A)
		&& (to != &REGISTERS.B) && (from != &REGISTERS.B)
		&& (to != &REGISTERS.CCR) && (from != &REGISTERS.CCR)) {

		*(uint16_t*)(to) = *(uint16_t*)(from);
		if (*(uint16_t*)(to) & 0x8000)
			set('n');
		else
			unset('n');
		if (*(uint16_t*)(to))
			unset('z');
		else
			set('z');
	} else {
		*(uint8_t*)(to) = *(uint8_t*)(from);
		if ((to != &REGISTERS.CCR) && (from != &REGISTERS.CCR)) {
			if (*(uint8_t*)(to) & 0x80)
				set('n');
			else
				unset('n');
			if (*(uint8_t*)(to))
				unset('z');
			else
				set('z');
		}
	}
}

void tpa(void) {
	REGISTERS.A = REGISTERS.CCR;
}

void tsx(void) {
	REGISTERS.X = REGISTERS.SP;
}

void tsy(void) {
	REGISTERS.Y = REGISTERS.SP;
}

void txs(void) {
	REGISTERS.SP = REGISTERS.X;
}

void tys(void) {
	REGISTERS.SP = REGISTERS.Y;
}

void exg(uint8_t *first, uint8_t *second) {
	uint8_t _a = *first;
	*first = *second;
	*second = _a;
}

void exg_large(uint16_t *first, uint16_t *second) {
	uint16_t _a = *first;
	*first = *second;
	*second = _a;
}

void xgdx(void) {
	uint16_t _a = REGISTERS.D;
	REGISTERS.D = REGISTERS.X;
	REGISTERS.X = _a;
}

void xgdy(void) {
	uint16_t _a = REGISTERS.D;
	REGISTERS.D = REGISTERS.Y;
	REGISTERS.Y = _a;
}

void sex(uint8_t *from, uint16_t *to) {
	*to = (uint16_t)(((*from & 0x80) ? 0xFF00 : 0x0000) + (*from));
}
