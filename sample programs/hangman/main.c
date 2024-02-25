#include "game.h"

int main(void)
{
    Game_Init();

    for (;;)
    {
        Game_Run();
    }
}
