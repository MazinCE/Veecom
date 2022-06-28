
#include "util.h"
#include <string.h>
#include <stdlib.h>

#define PUT_PIXEL(x, y, screen) (screen[y] |= (0x80 >> x))

typedef struct
{
   int8_t x;
   int8_t y;
} Point;

typedef struct
{
   Point body[64];
   uint8_t body_len;
   Point dir;

} Player;

typedef struct
{
   uint8_t feild[8];
   Player player;
   Point food;
   uint16_t score;
   char score_str[5];
} Snake;

void Snake_init(Snake *game)
{
   game->player.body[0].x = 4;
   game->player.body[0].y = 4;
   game->player.dir.x = 0;
   game->player.dir.y = -1;
   game->player.body_len = 1;

   // Read data from random generator
   game->food.x = READ_BYTE(PRA);
   game->food.y = READ_BYTE(PRA);
}

void Snake_run(Snake *game)
{
   while (1)
   {
      memset(game->feild, 0, sizeof(game->feild));

      uint8_t key = READ_BYTE(PRB) & 0x7F;

      switch (key)
      {
      case 'a':
         if (game->player.dir.x != 1) // Prevent snake from moving on the oppisite direction
         {
            game->player.dir.x = -1;
            game->player.dir.y = 0;
         }
         break;
      case 'd':
         if (game->player.dir.x != -1)
         {
            game->player.dir.x = 1;
            game->player.dir.y = 0;
         }
         break;
      case 'w':
         if (game->player.dir.y != 1)
         {
            game->player.dir.y = -1;
            game->player.dir.x = 0;
         }
         break;
      case 's':
         if (game->player.dir.y != -1)
         {
            game->player.dir.y = 1;
            game->player.dir.x = 0;
         }
         break;
      default:
         break;
      }

      Point head_pos = game->player.body[0];

      game->player.body[0].x = (game->player.body[0].x + game->player.dir.x) % 8;
      game->player.body[0].y = (game->player.body[0].y + game->player.dir.y) % 8;

      // Check for head boundry crossing
      if (game->player.body[0].x < 0)
      {
         game->player.body[0].x == 7;
      }

      if (game->player.body[0].y < 0)
      {
         game->player.body[0].y = 0;
      }

      // Check head collision with food
      if (game->food.y == game->player.body[0].y)
      {
         if (game->food.x == game->player.body[0].x)
         {
            // Read data from random generator
            game->food.x = READ_BYTE(PRA);
            game->food.y = READ_BYTE(PRA);

            if (game->player.body_len < 64)
            {
               game->player.body_len++;
            }

            game->score += 10;
         }
      }

      // Move body
      for (uint8_t i = 1; i < game->player.body_len; ++i)
      {
         Point temp = game->player.body[i];

         // Check head collision with body
         if (game->player.body[0].y == temp.y)
         {
            if (game->player.body[0].x == temp.x)
            {
               WRITE_BYTE(DDRA, OUTPUT);
               itoa(game->score, game->score_str, 10);
               Terminal_write("           Game Over\n");
               Terminal_write("           Score: ");
               Terminal_write(game->score_str);

               // Set PRA back as input for the random generator
               WRITE_BYTE(DDRA, INPUT);

               Timer_delay(60);
               return;
            }
         }

         game->player.body[i] = head_pos;
         head_pos = temp;
      }

      // Draw snake
      for (uint8_t i = 0; i < game->player.body_len; ++i)
      {
         PUT_PIXEL(game->player.body[i].x, game->player.body[i].y, game->feild);
      }

      // Draw food
      PUT_PIXEL(game->food.x, game->food.y, game->feild);

      // Send data to led matrix
      DMA_transfer(game->feild, sizeof(game->feild));
   }
}

int main()
{
   // Set PRA as output for writing to terminal
   WRITE_BYTE(DDRA, OUTPUT);

   // Set PRB as input for reading keyboard
   WRITE_BYTE(DDRB, INPUT);

   Terminal_write("*RVCOM 2.0*\n");
   Terminal_write("[Mini Snake Game]\n");
   Terminal_write("Use W,S,A,D to navigate\n\n");

   // Now set PRA as input for the random generator (PRA is shared between terminal and Random generator)
   WRITE_BYTE(DDRA, INPUT);

   Snake game;

   while (1)
   {
      Snake_init(&game);
      Snake_run(&game);
   }
}