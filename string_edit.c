#include "main.h"
/**
 * change_sp - replaces a substring with a given string
 * @s_input: input string
 * @before: index of the first character of the substring to be replaced
 * @after: index of the last character of the substring to be replaced
 * @var: string to replace the substring
 * @var_l: length of the string to replace the substring
 * Return: pointer to the new string
 */
char *change_sp(char *s_input, int before, int after, char *var, int var_l)
{
	int len = before + var_l + length(s_input + after) + 2;
	int i;
	char *str = (char *)malloc(len);

	if (!str)
	{
		free(str);
		exit(1);
		return (NULL);
	}

	for (i = 0; i < len; i++)
	{
		if (i <= before)
		{
			str[i] = s_input[i];
		}
		else if (i <= before + var_l)
		{
			str[i] = var[i - before - 1];
		}
		else
		{
			str[i] = s_input[after++];
		}
	}
	str[i] = '\0';
	free(s_input);
	return (str);
}
/**
 * before_after - finds the first occurence of a specifier
 * @str: input string
 * @start: index to start searching from
 * @t: array of specifiers
 * @before: pointer to the index of the first character of the specifier
 * @after: pointer to the index of the last character of the specifier
 * @nul_c: pointer to the null counter
 * @args: arguments list
 * Return: pointer to the specifier
 */
char *before_after(char *str, int start, types t[], int *before,
				   int *after, int *nul_c, va_list args)
{
	int i;
	char *p = NULL;
	char sp_letter = -100;

	for (i = start; str[i]; i++)
	{
		if (str[i] == '%' && sp_true(str + i, t))
		{
			int a_len = sp_true(str + i, t);
			char *flags;

			*after = i + a_len + 1;
			*before = i - 1;
			flags = getFlag(str + i + 1, a_len - 1);

			p = get_value(str + i, t, args, nul_c, &sp_letter,
						  flags);

			free(flags);

			return (p);
		}
	}
	*before = i;
	*after = i;
	return (p);
}
/**
 * sp_true - checks if a character is a specifier
 * @str: input string
 * @t: array of specifiers
 * Return: length of the specifier if it exists, 0 otherwise
 */
int sp_true(char *str, types t[])
{
	int i, j;

	for (i = 0; str[i]; i++)
	{
		for (j = 0; t[j].type; j++)
		{
			if (str[i] == t[j].type && i)
				return (i);
		}
	}
	return (0);
}
/**
 * get_value - gets the value of a specifier
 * @str: input string
 * @t: array of specifiers
 * @args: arguments list
 * @nul_c: pointer to the null counter
 * @sp_letter: letter of the current sp
 * @flags: string of flags
 * Return: pointer to the value of the specifier
 */
char *get_value(char *str, types t[], va_list args,
				int *nul_c, char *sp_letter, char *flags)
{
	int i, j;

	for (i = 0; str[i]; i++)
	{
		for (j = 0; t[j].type; j++)
		{
			if (str[i] == t[j].type && i)
			{
				char *p = t[j].func(args, flags);

				if (str[i] == 'c' && !p[0])
					*nul_c += 1;
				*sp_letter = t[j].type;
				return (p);
			}
		}
	}
	return (NULL);
}

/**
 * getFlag - extract flags from text
 * @str: string to extract flags from
 * @steps: number of flags
 * Return: string of the flags
 */
char *getFlag(char *str, int steps)
{
	int i = 0;
	char *tags = (char *)malloc(steps + 1);

	if (!tags)
	{
		free(tags);
		exit(1);
		return (NULL);
	}
	for (i = 0; i < steps; i++)
	{
		tags[i] = str[i];
	}
	tags[i] = '\0';
	return (tags);
}
