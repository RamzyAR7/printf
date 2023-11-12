#include "main.h"
int length(char *str)
{
	int i = 0;

	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}
char *copy(char *str, char *copyTo)
{
	int i = 0;
	int len = length(str);
	char *copy = (char *)malloc(len);

	free(copyTo);
	if (!str)
		return (NULL);

	for (i = 0; str[i]; i++)
		copy[i] = str[i];
	return (copy);
}
void print(char *str)
{
	write(1, str, length(str));
}
