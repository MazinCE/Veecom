#include "util.h"

void Terminal_Write_Char(char chr)
{
    *(volatile char *)(IO_ADDR + PA) = chr | 0x80;
}

void Terminal_Write(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        Terminal_Write_Char(str[i]);
        i++;
    }
}

void Terminal_Clear()
{
    *(volatile short *)(IO_ADDR + PA) = 0x100;
}

char Keyboard_Read()
{
    *(volatile char *)(IO_ADDR + PC) = 0x01;
    char data = *(volatile char *)(IO_ADDR + PC);
    return data;
}

void __attribute__((optimize("O0"))) Sounder_Beep(int freq)
{
    *(volatile short *)(IO_ADDR + PB) = (freq & 0x3fff) | 0x4000;
}

int fac(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n * fac(n - 1);
}

int power(int val, int n)
{
    if (n == 0)
        return 1;

    int temp = power(val, n / 2);

    if (n % 2 == 0)
        return temp * temp;

    return val * temp * temp;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *arr, int n)
{
    if (n == 1)
        return;

    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
            swap(&arr[i], &arr[i + 1]);

    bubble_sort(arr, n - 1);
}
