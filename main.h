#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

/**
 * struct spcf - select the collect function based on specifier
 * @spc: specifier provided
 * @f: function to use to print
 */
struct spcf
{
	char *spc;
	int (*f)(va_list);
};
typedef struct spcf selct;

int selector(const char *format, selct func[], va_list args);
int print_char(va_list list);
int print_string(va_list list);
int print_percent(va_list list);
int _putchar(char c);
int _printf(const char *format, ...);
int print_int(va_list arg);

#endif
