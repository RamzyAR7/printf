#include "main.h"

/**
 * print_string - prints a string
 * @args: arguments list
 *
 * Return: pointer to string
 */
char *print_string(va_list args)
{
	char *p = va_arg(args, char *);

	if (!p)
		p = "(null)";
	if (!p[0])
		p = NULL;
	return (p);
}
/**
 * print_character - prints a character
 * @args: arguments list
 *
 * Return: pointer to character
 */
char *print_character(va_list args)
{
	char *c = (char *)malloc(2);
	int asci = va_arg(args, int);

	if (!c)
	{
		free(c);
		exit(1);
		return (NULL);
	}
	c[0] = (char)asci;
	c[1] = '\0';
	return (c);
}
/**
 * print_percent - prints a percent sign
 * @args: arguments list
 *
 * Return: pointer to percent sign
 */
char *print_percent(va_list args)
{
	char *p = (char *)args;

	p = (char *)malloc(2);
	if (!p)
	{
		free(p);
		exit(1);
		return (NULL);
	}
	p[0] = '%';
	p[1] = '\0';
	return (p);
}
/**
 * print_integer - Converts an integer to a string using recursion
 * @args: Variadic arguments list, expecting an integer to be printed
 *
 * Return: Pointer to a dynamically allocated string representing the integer
 */
char *print_integer(va_list args)
{
	int num = va_arg(args, int);
	char *buffer = malloc(12);
	char *p = buffer;

	if (!buffer)
	{
		free(buffer);
		exit(1);
		return (NULL);
	}

	if (num < 0)
	{
		*p = '-';
		p++;
	}

	p = print_rec(num, p);
	*p = '\0';

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
