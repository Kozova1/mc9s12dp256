#include "cpu.h"
// easy way to set a specific bit in the CCR
void set(char which) {
	switch(which) {
		case 'c':
		case 'C':
			REGISTERS.CCR |= 0x01;
			break;
		case 'v':
		case 'V':
			REGISTERS.CCR |= 0x02;
			break;
		case 'z':
		case 'Z':
			REGISTERS.CCR |= 0x04;
			break;
		case 'n':
		case 'N':
			REGISTERS.CCR |=0x08;
			break;
		case 'i':
		case 'I':
			REGISTERS.CCR |= 0x10;
			break;
		case 'h':
		case 'H':
			REGISTERS.CCR |= 0x20;
			break;
		case 'x':
		case 'X':
			REGISTERS.CCR |= 0x40;
			break;
		case 's':
		case 'S':
			REGISTERS.CCR |= 0x80;
	}	
}

void unset(char which) {
	switch(which) {
		case 'c':
		case 'C':
			REGISTERS.CCR &= (~0x01);
			break;
		case 'v':
		case 'V':
			REGISTERS.CCR &= (~0x02);
			break;
		case 'z':
		case 'Z':
			REGISTERS.CCR &= (~0x04);
			break;
		case 'n':
		case 'N':
			REGISTERS.CCR &= (~0x08);
			break;
		case 'i':
		case 'I':
			REGISTERS.CCR &= (~0x10);
			break;
		case 'h':
		case 'H':
			REGISTERS.CCR &= (~0x20);
			break;
		case 'x':
		case 'X':
			REGISTERS.CCR &= (~0x40);
			break;
		case 's':
		case 'S':
			REGISTERS.CCR &= (~0x80);
	
	}
}
