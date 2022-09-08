#ifndef UTIL_H
#define UTIL_H

#include <stdint.h>

#define PRA 0xFFFF0
#define PRB 0xFFFF2
#define DDRA 0xFFFF1
#define DDRB 0xFFFF3

#define TIMER_CMP 0xFFFF5
#define TIMER_CTRL 0xFFFF6
#define TIMER_FLAG 0xFFFF7

#define DMA_ADDR_REG 0xFFFF8
#define DMA_BLOCK_SIZE_REG 0xFFFF9
#define DMA_START_TRANSFER 0xFFFFA

#define OUTPUT 0xFF
#define INPUT 0x00

#define WRITE_BYTE(addr, byte) *(volatile uint8_t *)(addr) = byte
#define READ_BYTE(addr) *(volatile uint8_t *)(addr)

void DMA_transfer(const uint8_t *block_addr_ptr, uint16_t block_size);
void Terminal_printChar(char c);
void Terminal_print(const char *str);
void Terminal_println(const char *str);
char Keyboard_read(void);
void Timer_delay(uint8_t ticks);
int Math_pow(int a, int n);

#endif