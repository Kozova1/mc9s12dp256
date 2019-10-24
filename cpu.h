#ifndef CPU_H
#define CPU_H
#include "includes.h"
#define MEMORY_SIZE 66559
#define REGISTERS_SIZE 0x03FF
#define EEPROM_SIZE 0x0FFF
#define EEPROM_OFFSET 0x0000
#define RAM_SIZE 0x2FFF
#define RAM_OFFSET 0x1000
#define FLASH_EEPROM_SIZE 262144

uint8_t EEPROM_PAGE;
FILE *FLASH_EEPROM_FILE;
uint8_t CURRENT_EEPROM_PAGE[0x3FFF];
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

void init(void);
int isimm(Memory mem);

#endif
