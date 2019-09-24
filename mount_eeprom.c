#include "cpu.h"
#include "includes.h"
#include "set.h"

void mount_eeprom(void) {
	// TODO -> implement paging for flash EEPROM
	// CURRENT_EEPROM_PAGE = mmap(EEPROM_OFFSET, sizeof(uint8_t) * 0x3FFF, PROT_READ | PROT_WRITE, int fd, off_t offset);
}
