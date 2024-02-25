#include "utility.h"

int main(void)
{
   char* message = "printf is slow, it outputs a single\ncharacter at a time.\n";

   printf("%s", message);

   message = "\nDMA however, is BLAZINGLY fast!\n";

   dma_write(message);

   for(;;)
      ;
}
