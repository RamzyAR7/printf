#include "main.h"

/**
 * choose_flag - handle flags
 * @str: string to handle with flags
 * @flags: string of flags
 * @sp_letter: the current spicifyer letter
 * Return: pointer to character
 */
char *choose_flag(char *str, char *flags, char sp_letter)
{
	int i = 0;
	char *p = str;

	for (i = 0; flags[i]; i++)
	{
		switch (flags[i])
		{
		case '+':
			if (sp_letter == 'd' || sp_letter == 'i')
				p = flag_plus(p);
			continue;
			break;
		case '#':
			if (sp_letter == 'x' || sp_letter == 'X')
				p = flag_hash(p);
			continue;
			break;
		case ' ':
			if (sp_letter == '\0')
				p = flag_space(p);
			continue;
			break;

		default:
			if (sp_letter == 'd')
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
	char *p = str;

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
		free(str);
		return (p);
	}
	return (p);
}
/**
 * flag_hash - handle "#" flag
 * @str: string to handle with "#" flag
 * Return: pointer to character
 */
char *flag_hash(char *str)
{
	char *p = str;

	if (str[0] != '0' && str[0])
	{
		int i = 0;
		char *p = (char *)malloc(length(str) + 1);

		if (!p)
		{
			free(p);
			exit(1);
			return (NULL);
		}
		p[0] = '0';
		for (; str[i]; i++)
		{
			p[i + 1] = str[i];
		}
		p[i + 1] = str[i];
		free(str);
		return (p);
	}
	return (p);
}
/**
 * flag_space - handle " " flag
 * @str: string to handle with " " flag
 * Return: pointer to character
 */
char *flag_space(char *str)
{
	char *p = str;

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
		p[0] = ' ';
		for (; str[i]; i++)
		{
			p[i + 1] = str[i];
		}
		p[i + 1] = str[i];
		free(str);
		return (p);
	}
	return (p);
}
