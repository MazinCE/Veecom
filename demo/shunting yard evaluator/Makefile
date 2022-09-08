CC=C:/SysGCC/risc-v/bin/riscv64-unknown-elf-gcc
CFLAGS= -march=rv32im -mabi=ilp32 -nostartfiles -O3 -ffunction-sections
LDFLAGS=-T linker.ld

all: main.o

main.o: startup.c main.c token.c stack.c evaluator.c util.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -rf *.o *.bin *.txt

dump:
	C:/SysGCC/risc-v/bin/riscv64-unknown-elf-objdump -D main.o

size:
	C:/SysGCC/risc-v/bin/riscv64-unknown-elf-size -A main.o

bin:
	C:/SysGCC/risc-v/bin/riscv64-unknown-elf-objcopy -O binary main.o main.bin

