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
		free(str), str = NULL;
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
	if (s_input != NULL)
		free(s_input), s_input = NULL;
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
			char *flags = NULL;

			if (a_len > 0)
			{
				*after = i + a_len + 1;
				*before = i - 1;
				flags = getFlag(str + i + 1, a_len - 1, args);
			}
			else
			{
				*after = i - a_len + 1;
				*before = i;
			}
			p = get_value(str + i, t, args, nul_c, &sp_letter,
						  flags);
			if (flags)
				free(flags), flags = NULL;

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
	int i, j, flag_steps = 0;
	char flags[] = {'l', 'h', '\0'};

	for (i = 0; str[i]; i++)
	{
		for (j = 0; t[j].type; j++)
		{
			if (str[i] == t[j].type && i)
			{
				return (i);
			}
		}
	}
	for (i = 1; str[i]; i++)
	{
		for (j = 0; flags[j]; j++)
		{
			if (str[i] == flags[j])
			{
				flag_steps--;
			}
		}
		if (flag_steps != -i)
			return (flag_steps);
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
 * @args: arguments list
 * Return: string of the flags
 */
char *getFlag(char *str, int steps, va_list args)
{
	int i = 0;
	int j = 0;
	char *tags = (char *)malloc(steps + 20);

	if (!tags)
	{
		free(tags), tags = NULL;
		exit(1);
		return (NULL);
	}
	for (i = 0; i < steps; i++, j++)
	{
		if (str[j] == '*')
		{
			char *num;
			char *buffer = malloc(20);
			char *p = buffer;
			int k = 0, n = va_arg(args, int);

			if (!buffer)
			{
				free(buffer);
				exit(-1);
				return (NULL);
			}
			print_rec(n, p);
			*(p + 1) = '\0';
			num = copy(buffer, NULL);
			free(buffer);
			for (k = 0; num[k]; k++)
			{
				tags[i++] = num[k];
			}
		}
		else
			tags[i] = str[j];
	}
	tags[i] = '\0';
	return (tags);
}
