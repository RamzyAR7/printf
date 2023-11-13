#include "main.h"

/**
 * print_Uinteger - Converts an Unsinged integer to a string using recursion
 * @args: Variadic arguments list, expecting an integer to be printed
 * @flags: string of flags
 * Return: Pointer to a dynamically allocated string representing the integer
 */
char *print_Uinteger(va_list args, char *flags)
{
	char *buffer = malloc(12);
	char *p = buffer;

	if (!buffer)
	{
		free(buffer);
		exit(1);
		return (NULL);
	}

	if (*flags)
	{
		Uint_flags_handle(args, p, flags);
	}
	else
	{
		Uint_noFlags(va_arg(args, unsigned int), p);
	}
	return (buffer);
}

void Uint_noFlags(unsigned int num, char *p)
{
	p = print_rec(num, p);
	*p = '\0';
}

void Uint_flags_handle(va_list args, char *p, char *flags)
{
	int i = 0;
	int getBuffer = 0;
	char *buffer = p;

	for (i = 0; flags[i]; i++)
	{
		if (flags[i] == 'l')
		{
			unsigned long int num = va_arg(args, unsigned long int);

			p = print_recUL(num, p);
			*p = '\0';
			getBuffer++;
		}
		if (flags[i] == 'h')
		{
			unsigned short int num = va_arg(args, unsigned int);

			p = print_recUS(num, p);
			*p = '\0';
			getBuffer++;
		}
	}
	if (!getBuffer)
	{
		Uint_noFlags(va_arg(args, unsigned int), p);
	}
	buffer = copy(choose_flag(buffer, flags, 'd'), NULL);
}
