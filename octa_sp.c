#include "main.h"

/**
 * print_octa - Converts an Unsinged integer to an octal number
 * @args: Variadic arguments list, expecting an integer to be printed
 * @flags: string of flags
 * Return: Pointer to a dynamically allocated
 * string representing the octal number
 */
char *print_octa(va_list args, char *flags)
{
	char *p = NULL;

	if (*flags)
	{
		p = octa_flags_handle(args, p, flags);
	}
	else
	{
		p = intToOct(va_arg(args, int));
	}
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
 * intToOct - convert int as a octa number
 * @num: the integar number
 *
 * Return: pointer to the octa value
 */
char *intToOctL(unsigned long int num)
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
 * intToOct - convert int as a octa number
 * @num: the integar number
 *
 * Return: pointer to the octa value
 */
char *intToOctS(unsigned short int num)
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
char *octa_flags_handle(va_list args, char *p, char *flags)
{
	int i = 0;
	int getBuffer = 0;

	for (i = 0; flags[i]; i++)
	{
		if (flags[i] == 'l')
		{
			p = intToOctL(va_arg(args, unsigned long int));
			getBuffer++;
		}
		if (flags[i] == 'h')
		{
			p = intToOctS(va_arg(args, unsigned int));
			getBuffer++;
		}
	}
	if (!getBuffer)
	{
		p = intToOct(va_arg(args, int));
	}
	p = copy(choose_flag(p, flags, 'd'), NULL);
	return (p);
}
