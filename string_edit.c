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
 * @args: arguments list
 * Return: pointer to the specifier
 */
char *before_after(char *str, int start, types t[], int *before,
		    int *after, va_list args)
{
	int i;
	char *p = NULL;

	for (i = start; str[i]; i++)
	{
		if (str[i] == '%' && sp_true(str + i, t))
		{
			*before = i - 1;
			*after = i + sp_true(str + i, t) + 1;
			p = get_value(str + i, t, args);
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
 * Return: pointer to the value of the specifier
 */
char *get_value(char *str, types t[], va_list args)
{
	int i, j;

	for (i = 0; str[i]; i++)
	{
		for (j = 0; t[j].type; j++)
		{
			if (str[i] == t[j].type && i)
				return (t[j].func(args));
		}
	}
	return (NULL);
}
