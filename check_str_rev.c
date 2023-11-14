#include "main.h"
/**
 * print_str_rev - prints a string in reverse
 * @args: arguments list
 * @flags: string of flags
 * Return: pointer to string
 */
char *print_str_rev(va_list args, char *flags)
{
	char *str = va_arg(args, char *);
	char *p = NULL;
	int i = 0, j = 0, k = 0;

	while (str[k])
	{
		k++;
	}

	if (!str)
	{
		return (NULL);
	}
	p = (char *)malloc(k + 1);
	if (!p)
	{
		free(p);
		exit(1);
		return (NULL);
	}
	for (i = k - 1; i >= 0; i--)
	{
		p[j] = str[i];
		j++;
	}
	p[j] = '\0';
	if (*flags)
	{
		p = choose_flag(p, flags, 'r');
	}
	return (p);
}
/**
 * print_rot13 - prints a string in rot13
 * @args: arguments list
 * @flags: string of flags
 * Return: pointer to string
 */
char *print_Rot13(va_list args, char *flags)
{
	char *str = va_arg(args, char *);
	char *p = NULL;
	int i = 0, j = 0, k = 0, l = 0;
	char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	if (!str)
		return (NULL);

	while (str[l])
	{
		l++;
	}
	p = (char *)malloc(l + 1);
	if (!p)
	{
		free(p);
		exit(1);
		return (NULL);
	}
	for (i = 0; str[i]; i++)
	{
		for (j = 0; alpha[j]; j++)
		{
			if (str[i] == alpha[j])
			{
				p[k] = rot13[j];
				break;
			}
		}
		if (!alpha[j])
			p[k] = str[i];
		k++;
	}
	p[k] = '\0';
	if (*flags)
	{
		p = choose_flag(p, flags, 'R');
	}
	return (p);
}
