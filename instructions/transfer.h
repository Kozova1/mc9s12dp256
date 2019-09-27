#ifndef TRANSFER_H
#define TRANSFER_H
#include "../includes.h"
void tab(void);
void tap(void);
void tba(void);
void tfr(void *from, void *to);
void tpa(void);
void tsx(void);
void tsy(void);
void txs(void);
void tys(void);
void exg(uint8_t *first, uint8_t *second);
void exg_large(uint16_t *first, uint16_t *second);
void xgdx(void);
void xgdy(void);
void sex(uint8_t *from, uint16_t *to);
#endif
