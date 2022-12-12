#include "patterns.h"
#include "util.h"

int main()
{
    WRITE_BYTE(DDRA, OUTPUT);
    Terminal_println("Led Matrix Patterns");

    int currentPattren = 0;

    for (;;)
    {
        DMA_transfer(PATTERNS[currentPattren], PATTERN_SIZE[currentPattren]);
        currentPattren = (currentPattren + 1) % PATTERN_COUNT;
    }
}