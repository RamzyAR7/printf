#include "main.h"
/**
 * hex_flags_handle - handles the flags for hexadecimal conversion
 * @args: the list of arguments
 * @p: the buffer to store the result
 * @flags: the flags to apply
 * @type: the type of conversion
 *
 * Return: the formatted string
 */
char *hex_flags_handle(va_list args, char *p, char *flags, char type)
{
	int i = 0;
	int getBuffer = 0;

	for (i = 0; flags[i]; i++)
	{
		if (flags[i] == 'l')
		{
			p = intToHexaL(va_arg(args, unsigned long int), type);
			getBuffer++;
		}
		if (flags[i] == 'h')
		{
			p = intToHexaS(va_arg(args, unsigned int), type);
			getBuffer++;
		}
	}
	if (!getBuffer)
	{
		p = intToHexa(va_arg(args, int), type);
	}
	p = copy(choose_flag(p, flags, 'd'), NULL);
	return (p);
}
