#include "shell.h"

/**
 * _strtok - splits a string by seperator
 * @str: string to be split
 * @sep: string to check for seperators
 * Return: pointer to the first token
 */

char *_strtok(char *str, char *sep)
{
	static char *ptr = NULL;

	if (!str)
	{
		str = ptr;
		if (!str)
			return (NULL);
	}

	str += _strspn(str, sep);
	if (!(*str))
	{
		ptr = NULL;
		return (ptr);
	}

	ptr = str + _strcspn(str, sep);
	if (*ptr)
	{
		*ptr = '\0';
		ptr++;
	}
	else
	{
		ptr = NULL;
	}
	return (str);
}
