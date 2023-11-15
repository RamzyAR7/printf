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
		switch (flags[i])
		{
		case '+':
			if (sp_letter == 'd' || sp_letter == 'i')
				p = flag_plus(p);
			break;
		case '#':
			if (sp_letter == 'x' || sp_letter == 'X' || sp_letter == 'o')
				p = flag_hash(p, sp_letter);
			break;
		case ' ':
			if (sp_letter == 'd' || sp_letter == 'i')
				p = flag_space(p);
			break;
		case '-':
			if (sp_letter == 'd' || sp_letter == 'i')
				p = flag_minus(p);
			break;
		default:
			if (flags[i] > '0' && flags[i] <= '9' &&
				(flags[i - 1] <= '0' || flags[i - 1] > '9'))
			{
				if (flags[i - 1] == '.' || flags[i - 1] == '0' || flags[i - 1] == '-')
					p = flag_width(p, flags + i, flags[i - 1]);
				else
					p = flag_width(p, flags + i, ' ');
			}
			else if (flags[i] == '.' && (flags[i + 1] == '0' || flags[i + 1] == '\0'))
				p[0] = '\0';
			break;
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
			free(p), p = NULL;
			exit(1);
			return (NULL);
		}
		p[0] = '+';
		for (; str[i]; i++)
		{
			p[i + 1] = str[i];
		}
		p[i + 1] = str[i];

		if (str)
			free(str), str = NULL;
		return (p);
	}
	return (p);
}
/**
 * flag_hash - handle "#" flag
 * @str: string to handle with "#" flag
 * @type: type of specifier
 * Return: pointer to character
 */
char *flag_hash(char *str, char type)
{
	char *p = str;

	if (str[0] != '0' && str[0])
	{
		int i = 0, j = 2;
		char *p = (char *)malloc(length(str) + 2);

		if (!p)
		{
			free(p), p = NULL;
			exit(1);
			return (NULL);
		}
		p[0] = '0';
		p[1] = type;
		if (type == 'o')
			j--;
		for (; str[i]; i++)
		{
			p[j++] = str[i];
		}
		p[j++] = str[i];

		if (str)
			free(str), str = NULL;

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
			free(p), p = NULL;
			exit(1);
			return (NULL);
		}
		p[0] = ' ';
		for (; str[i]; i++)
		{
			p[i + 1] = str[i];
		}
		p[i + 1] = str[i];

		if (str)
			free(str), str = NULL;
		return (p);
	}
	return (p);
}
/**
 * flag_minus - handle "-" flag
 * @str: string to handle with "-" flag
 * Return: pointer to character
 */
char *flag_minus(char *str)
{
	char *p = str;

	if (str[0] != '-' && str[0])
	{
		int i = 0;
		char *p = (char *)malloc(length(str) + 1);

		if (!p)
		{
			free(p), p = NULL;
			exit(1);
			return (NULL);
		}
		for (; str[i]; i++)
		{
			p[i] = str[i];
		}
		p[i] = str[i];

		if (str)
			free(str), str = NULL;
		return (p);
	}
	return (p);
}
