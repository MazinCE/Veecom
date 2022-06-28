int main(void);

void _start(void) __attribute__((section(".init")));

void _start(void)
{
    __asm__ volatile("la gp, __global_pointer$;"
                     "la sp, _sp");
    main();
}