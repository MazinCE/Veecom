
int main(void);

void _start(void) __attribute__((naked, section(".init")));

void _start(void)
{
    __asm__ volatile(
        "la gp, _global_pointer;"
        "la sp, _sp;"
        "call main;");

    for (;;)
        ;
}