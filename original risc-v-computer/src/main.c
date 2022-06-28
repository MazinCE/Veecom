#include "monitor.h"

int main()
{
   Monitor monitor;

   Monitor_Init(&monitor);

   while (1)
   {
      Monitor_Run(&monitor);
   }
}
