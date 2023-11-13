#include "main.h"

/**
 * ulong_to_hexa - Converts an unsigned long integer to a hexadecimal string.
 * @value_p: The unsigned long integer to be converted.
 * @buffer_p: A buffer to store the resulting string.
 *
 * Description: Converts an unsigned long integer to a hexadecimal string
 * and stores it in a buffer. The buffer must be at least 17 bytes long
 * (16 characters for the string, plus a null terminator).
 */
void ulong_to_hexa(unsigned long value_p, char *buffer_p)
{
	static const char hex_digits[] = "0123456789abcdef";
	int i, start = 0;

	while (((value_p >> (4 * (15 - start))) & 0xF) == 0 && start < 15)
		start++;

	for (i = start; i < 16; i++)
	{
		buffer_p[i - start] = hex_digits[(value_p >> (4 * (15 - i))) & 0xF];
	}
	buffer_p[16 - start] = '\0'; /* Null-terminate the string */
}

/**
 * print_pointer - Creates a string representation of a pointer in hexadecimal.
 * @args: Variable argument list containing the pointer.
 * @flags: string of flags
 * Return: A string representation of the pointer.
 *
 * Description: Extracts a pointer from the variable argument list and converts
 * it to a hexadecimal string representation. The string is stored in a static
 * buffer, so it should be used or copied
 *  immediately after calling this function.
 */
char *print_pointer(va_list args, char *flags)
{
	static char buffer_p[19];
	void *ptr = copy(va_arg(args, char *), NULL);

	if (!ptr)
	{
		return ("(nil)");
	}

	buffer_p[0] = '0';
	buffer_p[1] = 'x';
	ulong_to_hexa((unsigned long)ptr, buffer_p + 2);
	if (*flags)
	{
		ptr = choose_flag(ptr, flags, 'p');
	}
	return (buffer_p);
}
