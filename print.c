#include "main.h"
/**
 * _printf - prints  specific formats for data 
 * @format: a string of format specifiers for the data 
 * @...: variable number of arguments that correspond to the format specifiers
 * Return: the total number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list list;
	int len = 0, i = 0, j, array_len;
	prt format_funcs[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_mod},
		{'d', print_int},
		{'i', print_int},
		{'b', print_binary},
	};
	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			len++;
		}
		else
		{
			i++;
			array_len = sizeof(format_funcs) / sizeof(format_funcs[0]);
			for (j = 0; j < array_len; j++)
			{
				if (format[i] == format_funcs[j].specifier)
				{
					len += format_funcs[j].print(list);
					break;
				}
			}
			if (format[i] != format_funcs[j].specifier)
			{
				putchar(format[--i]);
				len++;
			}
		} i++;
	}
	va_end(list);
	return (len);
}
