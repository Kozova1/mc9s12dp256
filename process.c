#include "cpu.h"
#include "includes.h"
#include "instructions_includes.h"

/* TODO -> Implement binary file parser (Binary to function)
 * Also convert between all addressing modes to *(MMAP.MEMORY + position)
 */

uint16_t dir_to_ext(uint8_t pos) {
	return (uint16_t) pos;
}

uint16_t didx_to_ext(uint16_t *reg) {
	return *reg + REGISTERS.D;
}

uint16_t rel_to_ext(uint16_t pos) {
	return (uint16_t) REGISTERS.PC + pos;
}
