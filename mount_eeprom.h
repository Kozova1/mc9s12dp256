#ifndef MOUNT_EEPROM_H
#define MOUNT_EEPROM_H

#include "includes.h"
#include "cpu.h"

int set_eeprom_file(void);

int map_eeprom(void);

int unmap_eeprom(void);

void close_file(void);

#endif
