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
		free(c);
		return (NULL);
	}
	p[0] = '%';
	p[1] = '\0';
	return (p);
}
