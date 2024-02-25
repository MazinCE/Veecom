#ifndef UTILITY_H
#define UTILITY_H

#include "iom.h"
#include "printf.h"

#define put_char _putchar
#define clear_terminal() put_char((char)12)

void dma_write(char *str);
void dma_nwrite(char *str, uint16_t len);

char read_key(void);

#endif
