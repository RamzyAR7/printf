#include "main.h"

/**
 * print_integer - Converts an integer to a string using recursion
 * @args: Variadic arguments list, expecting an integer to be printed
 * @flags: string of flags
 * Return: Pointer to a dynamically allocated string representing the integer
 */
char *print_integer(va_list args, char *flags)
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
		int_flags_handle(args, p, flags);
	}
	else
	{
		int_noFlags(va_arg(args, int), p);
	}

	return (buffer);
}
/**
 * print_rec - prints an integer recursively
 * @num: integer to print
 * @p: pointer to string
 *
 * Return: pointer to string
 */
char *print_rec(int num, char *p)
{
	if (num / 10)
		p = print_rec(num / 10, p);
	if (num % 10 < 0)
		*p = -(num % 10) + '0';
	else
		*p = (num % 10) + '0';
	return (p + 1);
}
/**
 * int_noFlags - prints an integer with no flags
 * @num: integer to print
 * @p: pointer to string
 *
 * Return: void
 */
void int_noFlags(int num, char *p)
{
	if (num < 0)
	{
		*p = '-';
		p++;
	}
	p = print_rec(num, p);
	*p = '\0';
}

/**
 * int_flags_handle - handles integer flags
 * @args: Variadic arguments list, expecting an integer to be printed
 * @p: pointer to string
 * @flags: string of flags
 *
 * Return: void
 */
void int_flags_handle(va_list args, char *p, char *flags)
{
	int i = 0;
	int getBuffer = 0;
	char *buffer = p;

	for (i = 0; flags[i]; i++)
	{
		if (flags[i] == 'l')
		{
			long int num = va_arg(args, long int);

			if (num < 0)
			{
				*p = '-';
				p++;
			}
			p = print_recL(num, p);
			*p = '\0';
			getBuffer++;
		}
		if (flags[i] == 'h')
		{
			short int num = va_arg(args, int);

			if (num < 0)
			{
				*p = '-';
				p++;
			}
			p = print_recS(num, p);
			*p = '\0';
			getBuffer++;
		}
	}
	if (!getBuffer)
	{
		int_noFlags(va_arg(args, int), p);
	}

	buffer = copy(choose_flag(buffer, flags, 'd'), NULL);
}
