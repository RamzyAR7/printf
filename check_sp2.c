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
