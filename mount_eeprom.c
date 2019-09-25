#include "includes.h"
#include "cpu.h"

void save_eeprom_to_file(void) {
	// save EEPROM to file and return it
	FLASH_EEPROM_FILE = fopen("/tmp/eeprom", "wb+");
	fwrite(FLASH_EEPROM,
		   sizeof(uint8_t),
		   sizeof(uint8_t) * FLASH_EEPROM_SIZE,
		   FLASH_EEPROM_FILE);
}

int map_eeprom(void) {
	// Load EEPROM from previously saved file to memory
	// convert c to file descriptor
	int fd = fileno(FLASH_EEPROM_FILE);
	//actually mapping the file to memory
	uint8_t *a = mmap(MMAP.EEPROM_WINDOW,
					  sizeof(uint8_t) * 0x3FFF,
					  PROT_READ | PROT_WRITE,
					  MAP_PRIVATE,
					  fd,
					  // we need to set the eeprom page to the wanted page
					  REGISTERS.PPAGE * sizeof(uint8_t) * 0x3FFF);
	close(fd); // close file descriptor, we don't need it anymore
	// if mapping failed, return -1
	if (a == MAP_FAILED) {
		return -1;
	}
	return 0;
}

int unmap_eeprom(void) {
	// unmount eeprom from memory window
	return munmap(MMAP.EEPROM_WINDOW,
		   		  sizeof(uint8_t) * 0x3FFF);
}

void close_file(void) {
	fclose(FLASH_EEPROM_FILE);
}
