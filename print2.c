#include "main.h"
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

void print_binary_recursive(unsigned int num, int *count){

	char digit;
    
	if (num > 1) {
	print_binary_recursive(num / 2, count);
	}
	digit = '0' + (num % 2);
	write(1, &digit, 1);
	(*count)++;
	}
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char num_str[12];
	int digit_count = 0;
 
	va_start(args, format);
	while (*format != '\0') 
		if (*format == '%'){
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

			case 'b': {
                    	unsigned int num = va_arg(args, unsigned int);
                    	print_binary_recursive(num, &count);
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
                    	break;                }
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
