#include "main.h"

/**
 * choose_flag - handle flags
 * @str: string to handle with flags
 * @flags: string of flags
 * Return: pointer to character
 */
char *choose_flag(char *str, char *flags)
{
	int i = 0;
	char *p = str;

	for (i = 0; flags[i]; i++)
	{
		switch (flags[i])
		{
		case '+':
			p = flag_plus(p);
			continue;
			break;

		default:
			break;
		}
	}
	return (p);
}

/**
 * flag_plus - handle "+"" flag
 * @str: string to handle with "+" flag
 * Return: pointer to character
 */
char *flag_plus(char *str)
{
	char *p = NULL;

	if (str[0] != '-' && str[0] != '+' && str[0])
	{
		int i = 0;
		char *p = (char *)malloc(length(str) + 1);

		if (!p)
		{
			free(p);
			exit(1);
			return (NULL);
		}
		p[0] = '+';
		for (; str[i]; i++)
		{
			p[i + 1] = str[i];
		}
		p[i + 1] = str[i];
		return (p);
	}
	return (p);
}
