#include "main.h"
/**
 * print_int - Prints an integer 
 *
 * @list: A va_list containing the integer value to print
 *
 * Return: The number 
 */
int print_int(va_list list)
{
	int number = va_arg(list, int), len = 0;
	unsigned int digits = number;

	if (number < 0)
	{
		putchar('-');
		digits *= -1;
		len++;
	}
	else if (number == 0)
	{
		putchar('0');
		return (1);
	}
	len += int_helper(digits);
	return (len);
}
/**
 * int_helper - Helps to manipulate an unsigned integer value
 *
 * @value: The unsigned integer value 
 *
 * Return: An integer value
 */
int int_helper(unsigned int value)
{
    int len;

    if (value == 0)
    {
        return (0);
    }
    len = (1 + int_helper(value / 10));
    putchar(value % 10 + '0');
    return (len);
}
