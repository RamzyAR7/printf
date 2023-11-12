#include "main.h"

/**
 * print_binary - print int as a binary
 * @args: arguments list
 *
 * Return: pointer to the binary value
 */
char *print_binary(va_list args)
{
	char *p = intToBin(va_arg(args, int));

	return (p);
}

/**
 * intToBin - convert int as a binary
 * @num: the integar number
 *
 * Return: pointer to the binary value
 */
char *intToBin(unsigned int num)
{
	char *bNum = malloc(32);
	char temp[32];
	int i = 0, j = 0;

	if (!bNum)
	{
		free(bNum);
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
		temp[i++] = num % 2 + '0';
		num /= 2;
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
 * print_hexa_upper - print int as a hex
 * @args: arguments list
 *
 * Return: pointer to the hex value
 */
char *print_hexa_upper(va_list args)
{
	char *p = intToHexa(va_arg(args, int), 'X');

	return (p);
}
/**
 * print_hexa_lower - print int as a hex
 * @args: arguments list
 *
 * Return: pointer to the hex value
 */
char *print_hexa_lower(va_list args)
{
	char *p = intToHexa(va_arg(args, int), 'x');

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
		free(bNum);
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
