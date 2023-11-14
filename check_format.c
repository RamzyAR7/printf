#include "main.h"

/**
 * check_valid_format - check if the input is valid
 * @format: format specifiers
 * Return: 1 if valid and 0 if not
 */
int check_valid_format(const char *format)
{
	int i = 0;
	int percent = 0;
	int letters = 0;

	while (format[i])
	{
		if (format[i] == '%')
		{
			percent++;
		}
		else if (format[i] != ' ')
		{
			letters++;
		}
		i++;
	}
	if (percent > 1 || (letters && percent) || percent != 1)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
