#include "main.h"

/**
 * print_Uinteger - Converts an Unsinged integer to a string using recursion
 * @args: Variadic arguments list, expecting an integer to be printed
 *
 * Return: Pointer to a dynamically allocated string representing the integer
 */
char *print_Uinteger(va_list args)
{
	unsigned int num = (unsigned int)va_arg(args, int);
	char *buffer = malloc(12);
	char *p = buffer;

	if (!buffer)
	{
		free(buffer);
		exit(1);
		return (NULL);
	}
	p = print_recU(num, p);
	*p = '\0';

	return (buffer);
}
/**
 * print_recU - prints an unsined integer recursively
 * @num: unsined integar integer to print
 * @p: pointer to string
 *
 * Return: pointer to string
 */
char *print_recU(unsigned int num, char *p)
{
	if (num / 10)
	{
		p = print_rec(num / 10, p);
	}
		*p = (num % 10) + '0';

	return (p + 1);
}

/**
 * print_octa - Converts an Unsinged integer to an octal number
 * @args: Variadic arguments list, expecting an integer to be printed
 * Return: Pointer to a dynamically allocated
 * string representing the octal number
 */
char *print_octa(va_list args)
{
	char *p = intToOct(va_arg(args, int));

	return (p);
}
/**
 * intToOct - convert int as a octa number
 * @num: the integar number
 *
 * Return: pointer to the octa value
 */
char *intToOct(unsigned int num)
{
	char *ONum = malloc(32);
	char temp[32];
	int i = 0, j = 0;

	if (!ONum)
	{
		free(ONum);
		exit(1);
		return (NULL);
	}
	if (num == 0)
	{
		ONum[0] = '0';
		ONum[1] = '\0';
		return (ONum);
	}
	while (num > 0)
	{
		temp[i++] = num % 8 + '0';
		num /= 8;
	}
	while (j < i)
	{
		ONum[j] = temp[i - j - 1];
		j++;
	}
	ONum[j] = '\0';
	return (ONum);
}
/**
 * print_stringS - prints a custom conversion string
 * @args: arguments list
 *
 * Return: pointer to a custom conversion string
 */
char *print_stringS(va_list args)
{
	char *p = va_arg(args, char *);
	int i = 0;


	if (!p)
	{
		p = "(null)";
		return (p);
	}
	if (!p[0])
	{
		p = NULL;
		return (p);
	}
	for (i = 0; p[i]; i++)
	{
		if (p[i] < 32 || p[i] >= 127)
		{
			char *hexNum = intToHexa(p[i], 'X');
			char *hex = malloc(5);

			if (!hex)
			{
				free(hex);
				exit(1);
				return (NULL);
			}
			p = copy(p, NULL);
			hex[0] = '\\';
			hex[1] = 'x';
			hex[2] = hexNum[0];
			hex[3] = hexNum[1] ? hexNum[1] : '0';
			hex[4] = '\0';
			p = change_sp(p, i - 1, i + 1, hex, 4);
			free(hexNum);
			free(hex);
		}
	}
	return (p);
}
