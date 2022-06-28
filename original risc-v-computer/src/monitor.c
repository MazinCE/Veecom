#include "monitor.h"
#include "util.h"
#include <string.h>
#include <stdlib.h>

void Monitor_Init(Monitor *monitor)
{
    monitor->chr_index = 0;
    monitor->tok_count = 0;

    monitor->cmd_table[0] = &Monitor_CLS;
    monitor->cmd_table[1] = &Monitor_POKE;
    monitor->cmd_table[2] = &Monitor_PEEK;
    monitor->cmd_table[3] = &Monitor_ADD;
    monitor->cmd_table[4] = &Monitor_SUB;
    monitor->cmd_table[5] = &Monitor_MUL;
    monitor->cmd_table[6] = &Monitor_DIV;
    monitor->cmd_table[7] = &Monitor_REM;
    monitor->cmd_table[8] = &Monitor_SORT;
    monitor->cmd_table[9] = &Monitor_FAC;
    monitor->cmd_table[10] = &Monitor_POW;
    monitor->cmd_table[11] = &Monitor_ECHO;
    monitor->cmd_table[12] = &Monitor_HELP;

    Monitor_Beep(monitor);
    Terminal_Write("Monitor Shell 1.0\n");
}

void Monitor_Run(Monitor *monitor)
{
    Terminal_Write("> ");

    Monitor_HandleInput(monitor);
    Monitor_Tokinize(monitor);
    Monitor_Evaluate(monitor);
}

void Monitor_Tokinize(Monitor *monitor)
{
    char *tok = strtok(monitor->keyboard_buff, " ");

    while (tok)
    {
        strcpy(monitor->tokens[monitor->tok_count++], tok);
        tok = strtok(0, " ");
    }
}

void Monitor_Evaluate(Monitor *monitor)
{
    if (monitor->tok_count > 9)
    {
        Monitor_Beep(monitor);
        Terminal_Write("> Buffer overflow\n");
        return;
    }

    char *cmd = monitor->tokens[0];

    for (int i = 0; i < NUM_COMMANDS; ++i)
    {
        if (strcmp(cmd, MONITOR_COMMANDS[i]) == 0)
        {
            if (monitor->tok_count < MONITOR_COMMAND_MIN_ARGS[i])
            {
                Monitor_Beep(monitor);
                Terminal_Write("> Insufficient number of arguments\n");
            }
            else if (monitor->tok_count > MONITOR_COMMAND_MAX_ARGS[i])
            {
                Monitor_Beep(monitor);
                Terminal_Write("> Too many arguments\n");
            }
            else
            {
                (monitor->cmd_table[i])(monitor);
            }
            memset(cmd, 0, 10);
            monitor->tok_count = 0;
            return;
        }
    }

    memset(cmd, 0, 10);
    monitor->tok_count = 0;
    Monitor_Beep(monitor);
    Terminal_Write("> Invalid command; type 'help' for command list.\n");
}

void Monitor_HandleInput(Monitor *monitor)
{
    char key = 0;

    while (key != 10)
    {
        key = Keyboard_Read();
        int chr_valid = key & 0x80;
        key &= 0x7f;

        if (chr_valid)
        {
            if (key == 8)
            {
                if (monitor->chr_index > 0)
                {
                    monitor->chr_index--;
                }
            }
            else if (key != 10)
            {
                monitor->keyboard_buff[monitor->chr_index++] = key;
            }

            Terminal_Write_Char(key);
        }
    }

    monitor->keyboard_buff[monitor->chr_index] = ' ';
    monitor->keyboard_buff[monitor->chr_index + 1] = '\0';
    monitor->chr_index = 0;
}

void Monitor_Print(Monitor *monitor, int val)
{
    itoa(val, monitor->temp_buff, 10);
    Terminal_Write("> ");
    Terminal_Write(monitor->temp_buff);
    Terminal_Write("\n");
}

void Monitor_Beep(Monitor *monitor)
{
    Sounder_Beep(700);
    for (int i = 0; i < 50; ++i){}
    Sounder_Beep(0);
}

void Monitor_CLS(Monitor *monitor)
{
    Terminal_Clear();
}

void Monitor_POKE(Monitor *monitor)
{
    int address = atoi(monitor->tokens[1]);
    int val = atoi(monitor->tokens[2]);

    if (address >= 0x800000)
    {
        *(volatile int *)(address) = val;
    }
    else
    {
        Monitor_Beep(monitor);
        Terminal_Write("> Invalid memory address\n");
    }
}

void Monitor_PEEK(Monitor *monitor)
{
    int address = atoi(monitor->tokens[1]);
    int val = *(volatile int *)(address);

    Monitor_Print(monitor, val);
}

void Monitor_ADD(Monitor *monitor)
{
    int opr1 = atoi(monitor->tokens[1]);
    int opr2 = atoi(monitor->tokens[2]);

    Monitor_Print(monitor, opr1 + opr2);
}

void Monitor_SUB(Monitor *monitor)
{
    int opr1 = atoi(monitor->tokens[1]);
    int opr2 = atoi(monitor->tokens[2]);

    Monitor_Print(monitor, opr1 - opr2);
}

void Monitor_MUL(Monitor *monitor)
{
    int opr1 = atoi(monitor->tokens[1]);
    int opr2 = atoi(monitor->tokens[2]);

    Monitor_Print(monitor, opr1 * opr2);
}

void Monitor_DIV(Monitor *monitor)
{
    int opr2 = atoi(monitor->tokens[2]);

    if (opr2 == 0)
    {
        Monitor_Beep(monitor);
        Terminal_Write("> Division by zero\n");
    }
    else
    {
        int opr1 = atoi(monitor->tokens[1]);
        Monitor_Print(monitor, opr1 / opr2);
    }
}

void Monitor_REM(Monitor *monitor)
{
    int opr1 = atoi(monitor->tokens[1]);
    int opr2 = atoi(monitor->tokens[2]);

    Monitor_Print(monitor, opr1 % opr2);
}

void Monitor_SORT(Monitor *monitor)
{
    int arr[10];
    char buff[10];

    for (int i = 1; i < monitor->tok_count; ++i)
    {
        arr[i - 1] = atoi(monitor->tokens[i]);
    }

    bubble_sort(arr, monitor->tok_count - 1);
    Terminal_Write("> ");

    for (int i = 0; i < monitor->tok_count - 1; ++i)
    {
        Terminal_Write(itoa(arr[i], buff, 10));
        Terminal_Write(" ");
    }

    Terminal_Write("\n");
}

void Monitor_FAC(Monitor *monitor)
{
    Monitor_Print(monitor, fac(atoi(monitor->tokens[1])));
}

void Monitor_POW(Monitor *monitor)
{
    int opr = atoi(monitor->tokens[1]);
    int n = atoi(monitor->tokens[2]);
    Monitor_Print(monitor, power(opr, n));
}

void Monitor_ECHO(Monitor *monitor)
{
    Terminal_Write(">");

    for (int i = 1; i < monitor->tok_count; ++i)
    {
        Terminal_Write(" ");
        Terminal_Write(monitor->tokens[i]);
    }

    Terminal_Write("\n");
}

void Monitor_HELP(Monitor *monitor)
{
    Terminal_Write("CLS     Clears terminal.\n");
    Terminal_Write("POKE    Writes a value to a specified address.\n");
    Terminal_Write("PEEK    Reads a value from a specified address.\n");
    Terminal_Write("ADD     Performs addition on two numbers.\n");
    Terminal_Write("SUB     Performs substraction on two numbers.\n");
    Terminal_Write("MUL     Performs multipication on two numbers.\n");
    Terminal_Write("DIV     Performs Division on two numbers.\n");
    Terminal_Write("REM     Performs Remiander of division.\n");
    Terminal_Write("SORT    Bubble sorts a list of numbers.\n");
    Terminal_Write("FAC     Calculate factorial of a number.\n");
    Terminal_Write("POW     Calculate nth power of a number.\n");
    Terminal_Write("ECHO    Displays a message.\n");
    Terminal_Write("HELP    Provides Help information for commands.\n");
}