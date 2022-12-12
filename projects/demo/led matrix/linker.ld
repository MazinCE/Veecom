OUTPUT(riscv)
ENTRY(_start)

MEMORY
{
    RAM (rwx): ORIGIN = 0x00000, LENGTH = 0xffeff
}

SECTIONS
{
    __stack_size = 4K;

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
        PROVIDE( __global_pointer$ = .);
    } > RAM

    .bss :
    {
        *(.bss)
    }

    .stack ORIGIN(RAM) + LENGTH(RAM) - __stack_size :
    {
        PROVIDE( _sp = .); 
    } >RAM
}