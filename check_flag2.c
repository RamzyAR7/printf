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
