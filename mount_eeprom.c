#include "includes.h"
#include "cpu.h"

/* Here we handle saving the Flash EEPROM to a file
 * and then mmap(3) it to its respective memory window (Page)
 */

struct page_result {
	int unmap_result;
	int map_result;
};

int page_result_cmp(struct page_result a, struct page_result b) {
	if(a.unmap_result != b.unmap_result)
		return 0;
	if(a.map_result != b.map_result)
		return 0;
	return 1;
}

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
					  MAP_PRIVATE, fd,
					  // we need to set the eeprom page to the wanted page
					  REGISTERS.PPAGE * sizeof(uint8_t) * 0x3FFF);
	fread(FLASH_EEPROM, sizeof(uint8_t), sizeof(uint8_t) * FLASH_EEPROM_SIZE, FLASH_EEPROM_FILE);
	close(fd); // close file descriptor, we don't need it anymore
	// if mapping failed, return -1
	if (a == MAP_FAILED) {
		return 10;
	}
	return 0;
}

int unmap_eeprom(void) {
	// unmount eeprom from memory window
	return munmap(MMAP.EEPROM_WINDOW,
		   		  sizeof(uint8_t) * 0x3FFF);
}

int close_file(void) {
	return fclose(FLASH_EEPROM_FILE);
}

struct page_result page(uint8_t curr_page) {
	REGISTERS.PPAGE = curr_page - 0x30;
	int unmap_result = unmap_eeprom();
	int remap_result = map_eeprom();
	REGISTERS.PPAGE += 0x30;
	return (struct page_result){.unmap_result = unmap_result,
	   							.map_result = remap_result};
}
