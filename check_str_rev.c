#include "main.h"
/**
 * print_str_rev - prints a string in reverse
 * @args: arguments list
 * @flags: string of flags
 * Return: pointer to string
 */
char *print_str_rev(va_list args, char *flags)
{
	char *str = va_arg(args, char *);
	char *p = NULL;
	int i = 0, j = 0;

	if (!str)
		return (NULL);
	p = (char *)malloc(length(str) + 1);
	if (!p)
	{
		free(p);
		exit(1);
		return (NULL);
	}
	for (i = length(str) - 1; i >= 0; i--)
	{
		p[j] = str[i];
		j++;
	}
	p[j] = '\0';
	if (*flags)
	{
		p = choose_flag(p, flags, 'r');
	}
	return (p);
}
