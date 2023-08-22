#include "main.h"

void _printf(const char *inputs)
{
	write(STDOUT_FILENO,inputs, strlen(inputs));
}
