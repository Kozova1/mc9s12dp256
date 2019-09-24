#ifndef CPU_H
#define CPU_H
#include "includes.h"
#define MEMORY_SIZE 65536
#define REGISTERS_SIZE 0x03FF
#define EEPROM_SIZE 0x0FFF
#define EEPROM_OFFSET 0x0000
#define RAM_SIZE 0x2FFF
#define RAM_OFFSET 0x1000
#define FLASH_EEPROM_SIZE 262144

uint8_t EEPROM_PAGE;
uint8_t CURRENT_EEPROM_PAGE[0x3FFF];
uint8_t FLASH_EEPROM[FLASH_EEPROM_SIZE];
union {
	struct {
		uint8_t REGISTERS[REGISTERS_SIZE];
		uint8_t EEPROM[EEPROM_SIZE];
		uint8_t RAM[RAM_SIZE];
		uint8_t FIXED_FLASH_3E[0x3FFF];
		uint8_t EEPROOM_WINDOW[0x3FFF];
		union {
			struct {
				uint8_t FFLASH_WITH_BDM[0x3F00];
				uint8_t BDM[0x00FF];
			};
			uint8_t FIXED_FLASH_3F[0x3FFF];
		} LAST_3FFF;
	};
	uint8_t MEMORY[MEMORY_SIZE];
} MMAP;

struct {
	union {
		struct {
			uint8_t B;
			uint8_t A;
		};
		uint16_t D;
	};
	uint8_t CCR;
	uint16_t X,Y,SP,PC;
} REGISTERS;

void init(void);

#endif
