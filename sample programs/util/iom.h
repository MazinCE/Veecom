// Veecom I/O Map

#ifndef IOM_H
#define IOM_H

#include <stdint.h>

#define DAL *(volatile uint8_t*)(0xfff4) // DMA Block Address Lo (W)
#define DAH *(volatile uint8_t*)(0xfff5) // DMA Block Address Hi (W)
#define DSL *(volatile uint8_t*)(0xfff6) // DMA Block Size Lo    (W)
#define DSH *(volatile uint8_t*)(0xfff7) // DMA Block Size Hi    (W)
#define PAO *(volatile uint8_t*)(0xfff8) // Port A Output        (R/W)
#define PAI *(volatile uint8_t*)(0xfff9) // Port A Input         (R)
#define PBO *(volatile uint8_t*)(0xfffa) // Port B Output        (R/W)
#define PBI *(volatile uint8_t*)(0xfffb) // Port B Input         (R)
#define PCO *(volatile uint8_t*)(0xfffc) // Port C Output        (R/W)
#define PCI *(volatile uint8_t*)(0xfffd) // Port C Input         (R)
#define TVR *(volatile uint8_t*)(0xfffe) // Timer Value          (R/W)
#define TCR *(volatile uint8_t*)(0xffff) // Timer Control        (W)
#define TXP *(volatile uint8_t*)(0xffff) // Timer Expired Flag   (R)

#endif
