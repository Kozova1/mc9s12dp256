#ifndef MOUNT_EEPROM_H
#define MOUNT_EEPROM_H

#include "includes.h"
#include "cpu.h"


struct page_result {
	int unmap_result;
	int map_result;
};

int page_result_cmp(struct page_result a, struct page_result b);

int set_eeprom_file(void);

int map_eeprom(void);

int unmap_eeprom(void);

void close_file(void);

struct page_result page(uint8_t curr_page);


#endif
