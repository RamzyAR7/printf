#include "main.h"
/**
 * length - Calculates the length of a string
 * @str: The string to calculate the length of
 *
 * Return: The length of the string
 */
int length(char *str)
{
	int i = 0;

	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}
/**
 * copy - Copies a string
 * @str: The string to copy
 * @copyTo: The string to copy to
 *
 * Return: The copied string
 */
char *copy(char *str, char *copyTo)
{
	int i = 0;
	int len = length(str) + 1;
	char *copy = (char *)malloc(len);

	if (!copy)
	{
		free(copy), copy = NULL;
		free(copyTo), copyTo = NULL;
		exit(1);
		return (NULL);
	}
	if (copyTo)
	{
		free(copyTo), copyTo = NULL;
	}
	if (!str)
	{
		free(copy), copy = NULL;
		return (NULL);
	}
	else if (!str[1])
	{
		copy[0] = str[0];
		copy[1] = '\0';
	}
	else
		for (i = 0; str[i]; i++)
			copy[i] = str[i];
	copy[i] = str[i];
	return (copy);
}
