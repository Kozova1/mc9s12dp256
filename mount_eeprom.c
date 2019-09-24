#include "cpu.h"
#include "includes.h"
#include "set.h"

void mount_eeprom(void) {
	// experimental
	memcpy(MMAP.EEPROM_WINDOW, (FLASH_EEPROM + EEPROM_PAGE * 0x3FFF), sizeof(uint8_t) * 0x3FFF);
}
