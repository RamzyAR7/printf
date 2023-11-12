#include "main.h"

/**
 * _printf - Works like printf function
 * @format: format specifiers
 * Return: number of printed characters
 */

int _printf(const char *format, ...)
{
	char *result = NULL;
	char *current_spicifyer = NULL;
	int before = 0, after = 0, start = 0, len_res = 0, null_char = 0;
	int *b = &before, *f = &after, *nul_c = &null_char;
	va_list args;

	types t[] = {

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
		{'\0', NULL}

	};
	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);
	result = copy((char *)format, result);
	while (before != after || after == 0)
	{
		current_spicifyer = copy(before_after(result, start, t, b, f, nul_c, args),
								 current_spicifyer);
		if (before != after || after == 0)
			result = change_sp(result, before, after, current_spicifyer,
							   length(current_spicifyer));
		start = after - 1;
	}
	print(result);
	len_res = length(result) + null_char;
	free(result);
	return (len_res);
}
