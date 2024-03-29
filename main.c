#include "includes.h"
#include "cpu.h"
#include "set.h"
#include "mount_eeprom.h"

int end_sequence(int to_ret) {
	unmap_eeprom();
	close_file();
	return to_ret;
}

int init_sequence(void) {
	init();
	// Saving the EEPROM to a file so that we can map it to memory
	set_eeprom_file();
	// Getting the file descriptor for said file
	int fd = fileno(FLASH_EEPROM_FILE);
	// mapping the 3E fixed flash as required
	int *result1 = mmap(MMAP.FIXED_FLASH_3E,
						sizeof(uint8_t) * 0x3FFF,
						PROT_READ | PROT_WRITE,
						MAP_PRIVATE,
						fd,
						sizeof(uint8_t) * 0x43FD);
	// mapping the 3F fixed flash as required
	int *result2 = mmap(MMAP.FIXED_FLASH_3F,
						sizeof(uint8_t) * 0x3FFF,
						PROT_READ | PROT_WRITE,
						MAP_PRIVATE,
						fd,
						sizeof(uint8_t) * 0xC3FB);

	if (result1 == MAP_FAILED || result2 == MAP_FAILED) {
		return 2;
	}

	if (page_result_cmp(page(REGISTERS.PPAGE),
						(struct page_result){.unmap_result = -1,
											 .map_result = 10})) {
		return 1;
	}
	return 0;
}

int main(int argc, char *argv[]) {
	int excode = init_sequence();
	if (excode != 0) {
		return end_sequence(excode);
	}
	return end_sequence(0);
}
