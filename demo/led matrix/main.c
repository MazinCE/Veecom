#include "pattrens.h"
#include "util.h"

int main()
{
    WRITE_BYTE(DDRA, OUTPUT);
    Terminal_println("Led Matrix Pattrens");
    Terminal_println("Adjust clock freq as required");

    int currentPattren = 0;

    for (;;)
    {
        currentPattren = (currentPattren + 1) % PATTREN_COUNT;
        DMA_transfer(PATTRENS[currentPattren], PATTREN_SIZE[currentPattren]);
    }
}