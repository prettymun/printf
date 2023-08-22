#include <stdarg.h>
#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...) {
    
    int count = 0;  /*Count of characters printed*/
    char c;  /*Variable to temporarily store characters*/
    char *str;  /*Variable to temporarily store strings*/
    char num_number[20];/*Stores the number of integers*/
    
    va_list args;
    if (*format=='NULL'){
        return(-1);
    }

    va_start(args, format);
    
    while (*format)
    {
         if (*format != '%') {
            write(1,format,1); 
            count++; 
         }
         else {
            format++;
         }

         if(format=='\0'){
            break;
         }
            /*Handle conversion specifiers**/
            switch (*format) {
                case 'c': {
                    /*Print a single character*/
                    int c = va_arg(args, int);  /*Char is promoted to int*/
                    write(1, c, 1);
                    count++;
                    break;
                }
                case 's': {
                    /*Print a string*/
                    char str = va_arg(args, char*);
                    int str_len=0;

                    /*Calculate the length of the string*/
                    while(str[str_len]!='\0'){
                        str_len++;
                    
                    /*Write the string to standard output*/
                        write(1, str, str_len);
                        count += str_len;
                       
                    }
        
                    break;
                }
                
                case 'd':
                case 'i': {
                    // Print an integer
                    int num = va_arg(args, int);
                    int is_negative = 0;

                    if (num < 0) {
                        is_negative = 1;
                        num = -num;
                    }

                    int num_digits = 0;
                    do {
                        num_number[num_digits] = '0' + (num % 10);
                        num_digits++;
                        num /= 10;
                    } while (num > 0);

                    if (is_negative) {
                        num_number[num_digits] = '-';
                        num_digits++;
                    }

                    for (int i = num_digits - 1; i >= 0; i--) {
                        num_number[i] = num_number[num_digits - 1 - i];
                        count++;
                    }

                    break;
                }
                
                  case '%': {
                    /*Print a literal '%'*/
                    char percent='%';
                    write(1, &percent, 1);
                    count++;
                    break;
                }
                
                  default: {
                    /*Ignore unsupported format specifiers*/
                    break;
                }
            }
        
        format++;  /*Move to the next character*/
    }
    
    va_end(args);
    return count;
}
