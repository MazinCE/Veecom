#include "util.h"

int main(void)
{
   // Set port A as output por

   WRITE_BYTE(DDRA, OUTPUT);

   Terminal_println("Hello,world!");

   for(;;);
}