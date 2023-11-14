#include "main.h"
/**
 * _printf - Works like printf function
 * @format: format specifiers
 * Return: number of printed characters
 */

int _printf(const char *format, ...)
{
	char *result = NULL;
	int before = 0, after = 0, start = 0, len_res = 0, null_char = 0;
	int *b = &before, *f = &after, *nul_c = &null_char;
	va_list args;
	types *t = sp_struct();

	if (!format || !check_valid_format(format))
		return (-1);
	va_start(args, format), result = copy((char *)format, result);
	while (before != after || after == 0)
	{
		char *current_spicifyer = before_after(result, start, t, b, f, nul_c, args);

		if (before != after || after == 0)
			result = change_sp(result, before, after, current_spicifyer,
							   length(current_spicifyer));
		start = after - 1;
		if (current_spicifyer)
			free(current_spicifyer);
	}
	len_res = length(result) + null_char;
	write(1, result, len_res);
	if (result)
	{
		free(result);
	}
	free(t);
	return (len_res);
}

types *sp_struct()
{
	types *t = (types *)malloc(sizeof(types) * 14);
	int i = 0;
	types arr[] = {
		{'s', print_string},
		{'c', print_character},
		{'%', print_percent},
		{'d', print_integer},
		{'i', print_integer},
		{'b', print_binary},
		{'u', print_Uinteger},
		{'o', print_octa},
		{'X', print_hexa_upper},
		{'x', print_hexa_lower},
		{'S', print_stringS},
		{'p', print_pointer},
		{'r', print_str_rev},
		{'R', print_Rot13},
		{'\0', NULL}};

	while (i < 14)
	{
		t[i] = arr[i];
		i++;
	}
	return (t);
}
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
