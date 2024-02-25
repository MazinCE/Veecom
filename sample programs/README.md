# How to compile

You'll need a RISC-V C/C++ compiler, I personally use <a href="https://gnutoolchains.com/risc-v/"> this one </a> for my windows machine. <br />
Download and install `risc-v-gcc10.1.0.exe` and leave things to defaults. <br />
Open the terminal, navigate to the desired project (e.g., `empty-project`), and type `make -f ../Makefile` to compile the program. <br/>
You can also use `clean` target to remove `final.bin` and `final.elf` files by typing `make -f ../Makefile clean`.
 
<br />

From logisim load the `final.bin` file into Veecoms' main memory module.
