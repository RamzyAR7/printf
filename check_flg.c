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
	char *p = str, *temp;

	for (i = 0; flags[i]; i++)
	{
		switch (flags[i])
		{
		case '+':
			temp = flag_plus(p);
			break;
		case '#':
			temp = flag_hash(p);
			break;
		case ' ':
			temp = flag_space(p);
			break;
		default:
			temp = p;
			break;
		}

		if (temp != p)
		{
			free(p);
			p = temp;
		}
	}
	return (p);
}

/**
 * flag_plus - handle "+" flag
 * @str: string to handle with "+" flag
 * Return: pointer to character
 */
char *flag_plus(char *str)
{
	if (str == NULL || str[0] == '-' || str[0] == '+')
		return (str);

	char *p = (char *)malloc(length(str) + 2);

	if (!p)
		return (str);
	p[0] = '+';
	int i = 0;

	for (; str[i]; i++)
	{
		p[i + 1] = str[i];
	}
	p[i + 1] = '\0';
	return (p);
}

/**
 * flag_hash - handle "#" flag
 * @str: string to handle with "#" flag
 * Return: pointer to character
 */
char *flag_hash(char *str)
{
	if (str == NULL || str[0] == '0')
		return (str);

	char *p = (char *)malloc(length(str) + 2);

	if (!p)
		return (str);

	p[0] = '0';
	int i = 0;

	for (; str[i]; i++)
	{
		p[i + 1] = str[i];
	}
	p[i + 1] = '\0';
	return (p);
}

/**
 * flag_space - handle " " flag
 * @str: string to handle with " " flag
 * Return: pointer to character
 */
char *flag_space(char *str)
{
	if (str == NULL || str[0] == '-' || str[0] == '+')
		return (str);

	char *p = (char *)malloc(length(str) + 2);

	if (!p)
		return (str);

	p[0] = ' ';
	int i = 0;

	for (; str[i]; i++)
	{
		p[i + 1] = str[i];
	}
	p[i + 1] = '\0';
	return (p);
}
