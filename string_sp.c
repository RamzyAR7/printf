#include "main.h"

/**
 * print_string - prints a string
 * @args: arguments list
 * @flags: string of flags
 * Return: pointer to string
 */
char *print_string(va_list args, char *flags)
{
	char *p = copy(va_arg(args, char *), NULL);

	if (!p)
		p = "(null)";
	if (!p[0])
		p = NULL;
	if (*flags)
	{
		p = choose_flag(p, flags, 's');
	}
	return (p);
}