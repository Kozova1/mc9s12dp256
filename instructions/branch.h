#ifndef BRANCH_H
#define BRANCH_H
#include "../includes.h"
#include "../cpu.h"
void bcc(uint16_t pos);
void bcs(uint16_t pos);
void beq(uint16_t pos);
void bgt(uint16_t pos);
void bhi(uint16_t pos);
void bhs(uint16_t pos);
void ble(uint16_t pos);
void blo(uint16_t pos);
void bls(uint16_t pos);
void blt(uint16_t pos);
void bmi(uint16_t pos);
void bne(uint16_t pos);
void bpl(uint16_t pos);
void bra(uint16_t pos);
void brn(uint16_t pos);
void bvc(uint16_t pos);
void bvs(uint16_t pos);
void jmp(uint16_t pos);
#endif
