#ifndef MOUNT_EEPROM_H
#define MOUNT_EEPROM_H

#include "includes.h"
#include "cpu.h"

void save_eeprom_to_file(void);

int map_eeprom(void);

int unmap_eeprom(void);

void close_file(void);

#endif
