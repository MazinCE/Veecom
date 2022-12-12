int main(void);

void _start(void) __attribute__((naked, section(".init")));

void _start(void)
{
    __asm__ volatile(
        ".option push;"
        ".option norelax;"
        "la gp, __global_pointer$;"
        ".option pop;"
        "la sp, _sp;");

    main();
}