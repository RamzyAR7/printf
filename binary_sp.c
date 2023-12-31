#include "main.h"

/**
 * print_binary - print int as a binary
 * @args: arguments list
 * @flags: string of flags
 * Return: pointer to the binary value
 */
char *print_binary(va_list args, char *flags)
{
	char *p = NULL;

	if (*flags)
	{
		p = binary_flags_handle(args, p, flags);
	}
	else
	{
		p = intToBin(va_arg(args, int));
	}
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
 * intToBinL - convert unsigned long int to binary
 * @num: the unsigned long int number
 *
 * Return: pointer to the binary value
 */
char *intToBinL(unsigned long int num)
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
 * intToBinS - convert int as a binary number
 * @num: the integer number
 *
 * Return: pointer to the binary value
 */
char *intToBinS(unsigned short int num)
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
 * binary_flags_handle - handles binary conversion flags
 * @args: list of arguments
 * @p: pointer to the buffer
 * @flags: flags to modify the output
 *
 * Return: pointer to the buffer
 */
char *binary_flags_handle(va_list args, char *p, char *flags)
{
	int i = 0;
	int getBuffer = 0;

	for (i = 0; flags[i]; i++)
	{
		if (flags[i] == 'l')
		{
			p = intToBinL(va_arg(args, unsigned long int));
			getBuffer++;
		}
		if (flags[i] == 'h')
		{
			p = intToBinS(va_arg(args, unsigned int));
			getBuffer++;
		}
	}
	if (!getBuffer)
	{
		p = intToBin(va_arg(args, int));
	}
	p = copy(choose_flag(p, flags, 'b'), NULL);
	return (p);
}
