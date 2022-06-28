OUTPUT(riscv)
ENTRY(_start)

MEMORY
{
    RAM (rwx): ORIGIN = 0x00000, LENGTH = 0xffeff
}

SECTIONS
{
    __stack_size = 4K;
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

    .stack ORIGIN(RAM) + LENGTH(RAM) - __stack_size - 0xff :
    {
        PROVIDE( _sp = . ); 
    } >RAM
}