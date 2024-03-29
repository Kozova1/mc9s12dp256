#include "includes.h"
/* This file exists to emulate the CPU by emulating:
 * Memory
 * Registers
 * EEPROM and Flash EEPROM
 * it also contains a zeroing function
 */

// verify memory size since it seems to be wrong
#define MEMORY_SIZE 66559
#define REGISTERS_SIZE 0x03FF
#define EEPROM_SIZE 0x0FFF
#define EEPROM_OFFSET 0x0000
#define RAM_SIZE 0x2FFF
#define RAM_OFFSET 0x1000
#define FLASH_EEPROM_SIZE 262144

FILE *FLASH_EEPROM_FILE;
uint8_t FLASH_EEPROM[FLASH_EEPROM_SIZE];
union {
	struct {
		uint8_t FIXED_FLASH_3F[0x3FFF];
		uint8_t EEPROM_WINDOW[0x3FFF];
		uint8_t FIXED_FLASH_3E[0x3FFF];
		uint8_t RAM[RAM_SIZE];
		uint8_t EEPROM[EEPROM_SIZE];
		uint8_t REGISTERS[REGISTERS_SIZE];
	};
	uint8_t MEMORY[MEMORY_SIZE];
} MMAP;

struct Memory {
	uint8_t imm;
	uint16_t imm_ext;
	uint16_t pos;
	uint8_t *reg;
	uint16_t *reg_ext;
	char type;
};

typedef struct Memory Memory;

struct {
	union {
		struct {
			uint8_t B;
			uint8_t A;
		};
		uint16_t D;
	};
	union {
		struct {
			uint8_t c : 1;
			uint8_t v : 1;
			uint8_t z : 1;
			uint8_t n : 1;
			uint8_t i : 1;
			uint8_t h : 1;
			uint8_t x : 1;
			uint8_t s : 1;
		};
		uint8_t CCR;	
	};
	uint8_t PPAGE;
	uint16_t X,Y,SP,PC;
} REGISTERS;

void init(void) {
	for (int i = 0; i < MEMORY_SIZE; i++)
	{
		MMAP.MEMORY[i] = 0;
	}
	for (int i = 0; i < FLASH_EEPROM_SIZE; i++)
	{
		FLASH_EEPROM[i] = 0;
	}
	REGISTERS.CCR = 0;
	REGISTERS.D = 0;
	REGISTERS.X = 0;
	REGISTERS.Y = 0;
	REGISTERS.SP = 0;
	REGISTERS.PC = 0xBFFE; //TODO -> validate actual value
	REGISTERS.PPAGE = 0x30;
}

int isimm(Memory mem) {
	if (mem.type == 'i')
		return 1;
	else if (mem.type == 'a')
		return 0;
	else if (mem.type == 'r')
		return 2;
	else
		return 3;
}
