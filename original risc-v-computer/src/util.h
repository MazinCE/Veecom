#ifndef UTIL_H
#define UTIL_H

#define PA 0x00
#define PB 0x01
#define PC 0x02
#define IO_ADDR 0x7fffffc

void Terminal_Write_Char(char chr);
void Terminal_Write(const char *str);
void Terminal_Clear();

char Keyboard_Read(void);
void Sounder_Beep(int freq);

int fac(int n);
int power(int n, int exp);

void swap(int *a, int *b);
void bubble_sort(int *arr, int n);

#endif