#include "main.h"
/**
 * print_stringS - prints a custom conversion string
 * @args: arguments list
 * @flags: string of flags
 * Return: pointer to a custom conversion string
 */
char *print_stringS(va_list args, char *flags)
{
	char *p = copy(va_arg(args, char *), NULL);
	int i = 0;

	if (!p)
	{
		p = "(null)";
		return (p);
	}
	if (!p[0])
	{
		p = NULL;
		return (p);
	}
	for (i = 0; p[i]; i++)
	{
		if (p[i] < 32 || p[i] >= 127)
		{
			char *hexNum = intToHexa(p[i], 'X'), *hex = malloc(5);

			if (!hex)
			{
				free(hex), exit(1);
				return (NULL);
			}
			p = copy(p, NULL);
			hex[0] = '\\', hex[1] = 'x';
			if (hexNum[1] == '\0')
				hex[2] = '0', hex[3] = hexNum[0];
			else
				hex[2] = hexNum[0], hex[3] = hexNum[1];
			hex[4] = '\0', p = change_sp(p, i - 1, i + 1, hex, 4);
			if (hexNum)
				free(hexNum);
			if (hex)
				free(hex);
		}
	}
	if (*flags)
		p = choose_flag(p, flags, 'S');
	return (p);
}
