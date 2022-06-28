CC=C:/SysGCC/risc-v/bin/riscv64-unknown-elf-gcc
CFLAGS= -march=rv32im -mabi=ilp32 -nostartfiles -Os -ffunction-sections
LDFLAGS=-T linker.ld

all: main.o

main.o: src/startup.c src/main.c src/monitor.c src/util.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -rf *.o *.bin

dump:
	C:/SysGCC/risc-v/bin/riscv64-unknown-elf-objdump -D main.o

size:
	C:/SysGCC/risc-v/bin/riscv64-unknown-elf-size -A main.o

bin:
	C:/SysGCC/risc-v/bin/riscv64-unknown-elf-objcopy -O binary main.o main.bin

