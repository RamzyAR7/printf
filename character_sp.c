#include "main.h"

/**
 * print_character - prints a character
 * @args: arguments list
 * @flags: string of flags
 * Return: pointer to character
 */
char *print_character(va_list args, char *flags)
{
	int asci = va_arg(args, int);
	char *c = (char *)malloc(2);

	if (!c)
	{
		free(c), c = NULL;
		exit(1);
		return (NULL);
	}
	c[0] = (char)asci;
	c[1] = '\0';
	if (*flags)
	{
		c = choose_flag(c, flags, 'c');
	}
	return (c);
}
/**
 * print_percent - prints a percent sign
 * @args: arguments list
 * @flags: string of flags
 * Return: pointer to percent sign
 */
char *print_percent(va_list args, char *flags)
{
	char *p = (char *)args;

	p = (char *)malloc(2);
	if (!p)
	{
		free(p), p = NULL;
		exit(1);
		return (NULL);
	}
	p[0] = '%';
	p[1] = '\0';
	if (*flags)
	{
		p = choose_flag(p, flags, '%');
	}
	return (p);
}
