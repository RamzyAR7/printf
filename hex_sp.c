#include "main.h"

/**
 * print_hexa_upper - print int as a hex
 * @args: arguments list
 * @flags: string of flags
 * Return: pointer to the hex value
 */
char *print_hexa_upper(va_list args, char *flags)
{
	char *p = NULL;

	if (*flags)
	{
		p = hex_flags_handle(args, p, flags, 'X');
	}
	else
	{
		p = intToHexa(va_arg(args, int), 'X');
	}
	return (p);
}
/**
 * print_hexa_lower - print int as a hex
 * @args: arguments list
 * @flags: string of flags
 * Return: pointer to the hex value
 */
char *print_hexa_lower(va_list args, char *flags)
{
	char *p = NULL;

	if (*flags)
	{
		p = hex_flags_handle(args, p, flags, 'x');
	}
	else
	{
		p = intToHexa(va_arg(args, int), 'x');
	}
	return (p);
}
/**
 * intToHexa - convert int as a hex
 * @num: the integar number
 * @format: the format specifier
 * Return: pointer to the hex value
 */
char *intToHexa(unsigned int num, char format)
{
	char *bNum = malloc(32);
	char temp[32];
	int i = 0, j = 0;

	if (!bNum)
	{
		free(bNum), bNum = NULL;
		exit(1);
		return (NULL);
	}

	if (num == 0)
	{
		bNum[0] = '0';
		bNum[1] = '\0';
		return (bNum);
	}

	while (num > 0)
	{
		int remainder = num % 16;

		if (remainder < 10)
			temp[i++] = remainder + '0';
		else
			temp[i++] = remainder - 10 + (format == 'X' ? 'A' : 'a');
		num /= 16;
	}

	while (j < i)
	{
		bNum[j] = temp[i - j - 1];
		j++;
	}
	bNum[j] = '\0';

	return (bNum);
}

/**
 * intToHexaL - convert int as a hex
 * @num: the integar number
 * @format: the format specifier
 * Return: pointer to the hex value
 */
char *intToHexaL(unsigned long int num, char format)
{
	char *bNum = malloc(32);
	char temp[32];
	int i = 0, j = 0;

	if (!bNum)
	{
		free(bNum), bNum = NULL;
		exit(1);
		return (NULL);
	}

	if (num == 0)
	{
		bNum[0] = '0';
		bNum[1] = '\0';
		return (bNum);
	}

	while (num > 0)
	{
		int remainder = num % 16;

		if (remainder < 10)
			temp[i++] = remainder + '0';
		else
			temp[i++] = remainder - 10 + (format == 'X' ? 'A' : 'a');
		num /= 16;
	}

	while (j < i)
	{
		bNum[j] = temp[i - j - 1];
		j++;
	}
	bNum[j] = '\0';

	return (bNum);
}
/**
 * intToHexaS - convert int as a hex
 * @num: the integar number
 * @format: the format specifier
 * Return: pointer to the hex value
 */
char *intToHexaS(unsigned short int num, char format)
{
	char *bNum = malloc(32);
	char temp[32];
	int i = 0, j = 0;

	if (!bNum)
	{
		free(bNum), bNum = NULL;
		exit(1);
		return (NULL);
	}

	if (num == 0)
	{
		bNum[0] = '0';
		bNum[1] = '\0';
		return (bNum);
	}

	while (num > 0)
	{
		int remainder = num % 16;

		if (remainder < 10)
			temp[i++] = remainder + '0';
		else
			temp[i++] = remainder - 10 + (format == 'X' ? 'A' : 'a');
		num /= 16;
	}

	while (j < i)
	{
		bNum[j] = temp[i - j - 1];
		j++;
	}
	bNum[j] = '\0';

	return (bNum);
}
