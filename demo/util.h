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

void DMA_transfer(uint8_t *block_addr_ptr, uint16_t block_size)
{
   // The 20-bit DMA block address must be written to the DMA address register as three successive byte writes

   uint32_t block_addr = (uint32_t)block_addr_ptr; // Get pointer address
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

void Terminal_write_char(char c)
{
   WRITE_BYTE(PRA, c);
}

void Terminal_write(const char *str)
{
   int i = 0;
   while (str[i] != '\0')
   {
      Terminal_write_char(str[i]);
      i++;
   }
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
