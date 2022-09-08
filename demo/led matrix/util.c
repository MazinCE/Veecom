#include "util.h"

void DMA_transfer(const uint8_t *block_addr_ptr, uint16_t block_size)
{
   // The 20-bit DMA block address must be written to the DMA address register as three successive byte writes

   uint32_t block_addr = (uint32_t )block_addr_ptr; // Get pointer address
   uint8_t block_addr_lo = block_addr & 0xFF;
   uint8_t block_addr_mid = (block_addr >> 8) & 0xFF;
   uint8_t block_addr_hi = (block_addr >> 16) & 0x0F; // Get upper 4 bits only

   // Similarly the 16-bit block size is written as two successive byte writes
   // DMA transfer size must equal block_size - 1 hence (--block_size)

   uint8_t block_size_lo = (--block_size) & 0xFF;
   uint8_t block_size_hi = (block_size >> 8) & 0xFF;

   WRITE_BYTE(DMA_ADDR_REG, block_addr_lo);
   WRITE_BYTE(DMA_ADDR_REG, block_addr_mid);
   WRITE_BYTE(DMA_ADDR_REG, block_addr_hi);

   WRITE_BYTE(DMA_BLOCK_SIZE_REG, block_size_lo);
   WRITE_BYTE(DMA_BLOCK_SIZE_REG, block_size_hi);

   WRITE_BYTE(DMA_START_TRANSFER, 0xff);
}

void Terminal_printChar(char c)
{
   WRITE_BYTE(PRA, c);
}

void Terminal_print(const char *str)
{
   int i = 0;
   while (str[i] != '\0')
   {
      Terminal_printChar(str[i++]);
   }
}

void Terminal_println(const char *str)
{
   Terminal_print(str);
   WRITE_BYTE(PRA, '\n');
}

void Timer_delay(uint8_t ticks)
{
   // set compare register
   WRITE_BYTE(TIMER_CMP, ticks);

   // Start Timer in compare mode
   WRITE_BYTE(TIMER_CTRL, 0x03);

   // Wait for Timer to reach zero
   while (!READ_BYTE(TIMER_FLAG))
      ;

   // Stop timer
   WRITE_BYTE(TIMER_CTRL, 0x00);
}

int Math_pow(int a, int n)
{
   int r = 1;

   while (n != 0)
   {
      if ((n & 1) == 1)
      {
         r *= a;
      }

      n >>= 1;
      a *= a;
   }

   return r;
}
