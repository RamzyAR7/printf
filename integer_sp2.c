#include "main.h"

/**
 * print_recL - prints an integer recursively
 * @num: integer to print
 * @p: pointer to string
 *
 * Return: pointer to string
 */
char *print_recL(long int num, char *p)
{
	if (num / 10)
		p = print_recL(num / 10, p);
	if (num % 10 < 0)
		*p = -(num % 10) + '0';
	else
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
char *print_recS(short int num, char *p)
{
	if (num / 10)
		p = print_rec(num / 10, p);
	if (num % 10 < 0)
		*p = -(num % 10) + '0';
	else
		*p = (num % 10) + '0';
	return (p + 1);
}
