#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

typedef struct print_format
{
	char specifier;
	int (*print)(va_list list);
} prt;

int print_char(va_list list);
int print_str(va_list list);
int print_mod(va_list list);
int _printf(const char *format, ...);
int print_int(va_list list);
int int_helper(unsigned int value);
int print_binary(va_list list);
int binary_helper(int value);
#endif /* MAIN.H */
