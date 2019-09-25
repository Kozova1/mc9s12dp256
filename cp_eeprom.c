#include "cpu.h"
#include "includes.h"
#include "set.h"

// To be removed soonish

int eeprom_to_memory(void) {
	// experimental
	int *a = (int*)memcpy(MMAP.EEPROM_WINDOW,
		   				  (FLASH_EEPROM + EEPROM_PAGE * 0x3FFF),
		   				  sizeof(uint8_t) * 0x3FFF);
	if (a == NULL) {
		return -1;
	} else {
		return 0;
	}
}

int memory_to_eeprom(void) {
	// experimental
	int *a = (int*)memcpy((FLASH_EEPROM + EEPROM_PAGE * 0x3FFF),
						  MMAP.EEPROM_WINDOW,
						  sizeof(uint8_t) * 0x3FFF);
	if (a == NULL) {
		return -1;
	} else {
		return 0;
	}
}
