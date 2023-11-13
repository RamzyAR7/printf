#include "main.h"

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
