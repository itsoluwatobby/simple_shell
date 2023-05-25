#include "shell.h"

/**
 * _strncmp - compares two strings
 * @str1: the first string
 * @str2: the second string
 * @c: the number of characters to compare
 * Return: 0 if the strings are the same, a positive
 * or negative value otherwise depending on the
 * differnce btw the ascii values of the first char
 * which are differnt
 */

int _strncmp(char *str1, char *str2, int c)
{
	int i = 0, ret = 0;

	while (str2[i] && i < c)
	{
		if (str1[i] != str2[i])
		{
			ret = str1[i] - str2[i];
			return (ret);
		}
		i++;
	}
	return (ret);
}
