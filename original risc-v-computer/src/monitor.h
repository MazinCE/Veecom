#ifndef MONITOR_H
#define MONITOR_H

#define NUM_COMMANDS 13

static const char *MONITOR_COMMANDS[NUM_COMMANDS] = {
    "cls",
    "poke",
    "peek",
    "add",
    "sub",
    "mul",
    "div",
    "rem",
    "sort",
    "fac",
    "pow",
    "echo",
    "help",
};

static int MONITOR_COMMAND_MIN_ARGS[NUM_COMMANDS] =
    {
        1,
        3,
        2,
        3,
        3,
        3,
        3,
        3,
        2,
        2,
        3,
        2,
        1,
};

static int MONITOR_COMMAND_MAX_ARGS[NUM_COMMANDS] =
    {
        1,
        3,
        2,
        3,
        3,
        3,
        3,
        3,
        10,
        2,
        3,
        10,
        1,
};

typedef struct Monitor Monitor;
typedef void (*CommandFunc)(Monitor *);

struct Monitor
{
    int chr_index;
    int tok_count;
    char keyboard_buff[32];
    char temp_buff[10];
    char tokens[10][10];
    CommandFunc cmd_table[13];
};

void Monitor_Init(Monitor *monitor);
void Monitor_Run(Monitor *monitor);

void Monitor_Tokinize(Monitor *monitor);
void Monitor_Parse(Monitor *monitor);
void Monitor_Evaluate(Monitor *monitor);
void Monitor_HandleInput(Monitor *monitor);
void Monitor_Print(Monitor *monitor, int val);
void Monitor_Beep(Monitor* monitor);

void Monitor_CLS(Monitor *monitor);
void Monitor_POKE(Monitor *monitor);
void Monitor_PEEK(Monitor *monitor);
void Monitor_ADD(Monitor *monitor);
void Monitor_SUB(Monitor *monitor);
void Monitor_MUL(Monitor *monitor);
void Monitor_DIV(Monitor *monitor);
void Monitor_REM(Monitor *monitor);
void Monitor_SORT(Monitor *monitor);
void Monitor_FAC(Monitor *monitor);
void Monitor_POW(Monitor *monitor);
void Monitor_ECHO(Monitor *monitor);
void Monitor_HELP(Monitor *monitor);

#endif