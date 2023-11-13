#include "main.h"

char *choose_flag(char *str, char *flags)
{
	int i = 0;
	char *p = str;

	for (i = 0; flags[i]; i++)
	{
		switch (flags[i])
		{
		case '+':
			p = flag_plus(p);
			continue;
			break;

		default:
			break;
		}
	}
	return (p);
}

char *flag_plus(char *str)
{
	if (str[0] != '-' && str[0] != '+')
	{
		char *p = (char *)malloc(length(str) + 1);
		int i = 0;

		p[0] = '+';
		for (; str[i]; i++)
		{
			p[i + 1] = str[i];
		}
		p[i + 1] = str[i];
		return (p);
	}
}