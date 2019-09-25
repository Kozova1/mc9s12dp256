#ifndef LOAD_H
#define LOAD_H
#include "../includes.h"
void ldaa_mem(uint16_t offset_pos);
void ldaa(uint8_t val);
void ldab_mem(uint16_t offset_pos);
void ldab(uint8_t val);
void ldx_mem(uint16_t offset_pos);
void ldx(uint16_t val);
void ldy_mem(uint16_t offset_pos);
void ldy(uint16_t val);
void ldd_mem(uint16_t offset_pos);
void ldd(uint16_t val);
void lds_mem(uint16_t offset_pos);
void lds(uint16_t val);
#endif
