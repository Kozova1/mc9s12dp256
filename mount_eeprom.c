#include "includes.h"
#include "cpu.h"

/* Here we handle saving the Flash EEPROM to a file
 * and then mmap(3) it to its respective memory window (Page)
 */

int set_eeprom_file(void) {
	// read EEPROM from file to array
	int fd = open("/tmp/eeprom", O_CREAT | O_RDWR, 00644);
	FLASH_EEPROM_FILE = fdopen(fd, "rb+");
	if (FLASH_EEPROM_FILE == NULL)
		return 50;
	return 0;
}

int map_eeprom(void) {
	// Map file to memory (instead of array)
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
