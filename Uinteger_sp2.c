#include "main.h"

/**
 * print_recL - prints an integer recursively
 * @num: integer to print
 * @p: pointer to string
 *
 * Return: pointer to string
 */
char *print_recUL(unsigned long int num, char *p)
{
	if (num / 10)
	{
		p = print_rec(num / 10, p);
	}
	*p = (num % 10) + '0';

	return (p + 1);
}
/**
 * print_recS - prints an integer recursively
 * @num: integer to print
 * @p: pointer to string
 *
 * Return: pointer to string
 */
char *print_recUS(unsigned short int num, char *p)
{
	if (num / 10)
	{
		p = print_rec(num / 10, p);
	}
	*p = (num % 10) + '0';

	return (p + 1);
}