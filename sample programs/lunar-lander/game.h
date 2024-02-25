#ifndef GAME_H
#define GAME_H

#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    LANDING = 0,
    OUT_OF_FUEL,
    INVALID_BURN,
    ON_THE_MOON,
    MAX_STATES,
} GameState_e;

typedef void (*StateFn_t)(void);

typedef struct
{
    int16_t height;
    int8_t velocity;
    int8_t fuel_units;
    uint8_t burn;
    uint8_t time;
    GameState_e cur_state;
    StateFn_t state_table[MAX_STATES];
    char status[40];
    char burn_input_buff[2];
    uint8_t burn_input_index;
} Game_t;

void Game_Init(void);
void Game_Run(void);

void GAME_LANDING(void);
void GAME_BURN_INVALID(void);
void GAME_OUT_OF_FUEL(void);
void GAME_ON_THE_MOON(void);

#endif