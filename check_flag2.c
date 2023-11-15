#include "main.h"
/**
 * flag_zero - Adds a leading zero to a string if it starts with a minus sign
 *
 * @str: The string to modify
 *
 * Return: A pointer to the modified string, or NULL if memory allocation fails
 */
char *flag_zero(char *str)
{
	char *p = str;
	int i = 0, j = 0, len = length(str);

	if (str[0] == '-')
	{
		p = (char *)malloc(len);
		if (!p)
		{
			free(p), p = NULL;
			exit(1);
			return (NULL);
		}
		p[0] = '-';
		for (i = 1; i < len; i++)
			p[i] = '0';
		for (i = 1, j = 0; str[i]; i++, j++)
			p[i] = str[i - 1];
		p[i] = '\0';
	}
	return (p);
}

/**
 * flag_width - Adds padding to a string based on a specified field width
 *
 * @str: The string to modify
 * @nums: The field width specifier
 * @fuller: The filler to fill gabs
 * Return: A pointer to the modified string, or NULL if memory allocation fails
 */
char *flag_width(char *str, char *nums, char fuller)
{
	int f_w = get_nums_flag(nums);

	if (f_w == 0 && str[0] == '0' && fuller == '.')
	{
		str[0] = '\0';
		return (str);
	}
	if (f_w > length(str))
	{
		char *new_str = malloc(f_w + 1);
		int j = 0, i = 0;

		if (!new_str)
			free(new_str), exit(-1);
		if (str[j] == '-' && (fuller == '0' || fuller == '.'))
		{
			new_str[i++] = str[j++];
			if (fuller == '.')
				f_w++;
		}
		for (; i < f_w; i++)
			if (fuller != '-')
			{
				if (ch_ng(str, fuller) ? f_w - i < length(str) : f_w - i <= length(str))
					new_str[i] = str[j++];
				else
					new_str[i] = fuller == '.' || fuller == '-' ? '0' : fuller;
			}
			else
			{
				if (i < length(str))
					new_str[i] = str[j++];
				else
					new_str[i] = ' ';
			}
		free(str);
		return (new_str);
	}
	else
		return (str);
}

/**
 * get_nums_flag - Extracts a number from a string
 *
 * @str: The string to extract the number from
 *
 * Return: The extracted number
 */
int get_nums_flag(char *str)
{
	int i = 0, filed_width = 0;

	for (i = 0; str[i] >= '0' && str[i] <= '9'; i++)
	{
		if (filed_width)
			filed_width *= 10;
		filed_width += str[i] - '0';
	}
	return (filed_width);
}
/**
 * ch_ng - check for minus condition
 *
 * @str: The string to extract the number from
 * @fuller: the character of fuller
 * Return: The number
 */
int ch_ng(char *str, char fuller)
{
	if (str[0] == '-' && (fuller == '0' || fuller == '.'))
		return (1);
	else
		return (0);
}
