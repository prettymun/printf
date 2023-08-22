#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char num_str[12];
      int digit_count = 0;

    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++;

            switch (*format) {
                case 'c': {
                    char c = (char) va_arg(args, int);
                    write(1, &c, 1);
                    count++;
                    break;
                }

                case 's': {
                    const char *str = va_arg(args, const char *);
                    while (*str != '\0') {
                        write(1, str, 1);
                        str++;
                        count++;
                    }
                    break;
                }

                case 'd':
                case 'i': {
                    int num = va_arg(args, int);
                    if (num < 0) {
                        char minus = '-';
                        write(1, &minus, 1);
                        count++;
                        num = -num;
                    }
                   
                    do {
                        num_str[digit_count++] = '0' + (num % 10);
                        num /= 10;
                    } while (num > 0);
                    while (digit_count > 0) {
                        write(1, &num_str[--digit_count], 1);
                        count++;
                    }
                    break;
                }

                case '%': {
                    char percent = '%';
                    write(1, &percent, 1);
                    count++;
                    break;
                }

                default: {
                    write(1, format, 1);
                    count++;
                    break;
                }
            }
        } else {
            write(1, format, 1);
            count++;
        }

        format++;
    }

    va_end(args);
    return count;
}
