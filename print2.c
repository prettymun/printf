#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"


int _printf(const char *format, ...)
{
    va_list args;
    int written = 0;

    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++; /*Move past '%'*/
            
            /*Handle conversion specifiers*/
            switch (*format) {
                case 'c': {
                    char c = (char) va_arg(args, int);
                    write(1, &c, 1);
                    written++;
                    break;
                }
                case 's': {
                    const char *str = va_arg(args, const char *);
                    while (*str != '\0') {
                        write(1, str, 1);
                        str++;
                        written++;
                    }
                    break;
                }
                case '%': {
                    char percent = '%';
                    write(1, &percent, 1);
                    written++;
                    break;
                }
                default: {
                    write(1, format, 1);
                    written++;
                    break;
                }
            }
        } else {
            write(1, format, 1);
            written++;
        }
        
        format++;
    }

    va_end(args);
    return written;
}

