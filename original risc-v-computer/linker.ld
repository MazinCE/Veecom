OUTPUT(elf32-littleriscv)
ENTRY(_start)

MEMORY
{
    RAM (rwx): ORIGIN = 0x0000000, LENGTH = 0x7FFFFFB
}

SECTIONS
{
    __stack_size = DEFINED(__stack_size) ? __stack_size : 1K;
    PROVIDE(__stack_size = __stack_size);

    .init :
    {
        *(.init)
    } > RAM

    .text :
    {
        *(.text)
        *(.rodata)
    } > RAM

    .data :
    {
        *(.data)
        PROVIDE( __global_pointer$ = . + 0x800 );
    } > RAM

    .bss :
    {
        *(.bss)
    }

    .stack ORIGIN(RAM) + LENGTH(RAM) - __stack_size :
    {
        . += __stack_size;
        PROVIDE( _sp = . ); 
    } >RAM
}