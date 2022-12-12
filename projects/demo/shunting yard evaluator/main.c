#include "evaluator.h"
#include <stdlib.h>
#include "util.h"

int main()
{
    WRITE_BYTE(DDRA, OUTPUT);
    WRITE_BYTE(DDRB, INPUT);

    Evaluator_init();

    for (;;)
    {
        Evaluator_readInput();
        Evaluator_tokenize();
        Evaluator_parse();
        Evaluator_outputResult();
    }
}