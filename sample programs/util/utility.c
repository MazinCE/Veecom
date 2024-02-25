#include "utility.h"
#include "printf.h"

#include <string.h>

void _putchar(char character)
{
    PAO = character | 0x80;
    PAO = 0x00;
}

void dma_nwrite(char *str, uint16_t len)
{
   PCO |= 0x2;
   DSL = (uint8_t)(len & 0xff);
   DSH = (uint8_t)((len >> 8) & 0xff);
   DAL = (uint8_t)(((uintptr_t)str) & 0xff);
   DAH = (uint8_t)(((uintptr_t)(str) >> 8) & 0xff);
   PCO &= ~(0x2);
}

void dma_write(char *str)
{
   dma_nwrite(str, strlen(str));
}

// Blocking key read

char read_key(void)
{
   char k = 0;

   while ((k & 0x80) == 0)
   {
      k = PBI;
   }

   PCO |= 0x01;
   PCO &= ~(0x01);

   return k & 0x7f;
}
