#include "shell.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: string to duplicate
 *
 * Return: a pointer to a newly allocated space in memory
 */

char *_strdup(char *str)
{
	char *s;
	int i, len;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);
	s = malloc((sizeof(char) * len) + 1);
	if (s == NULL)
		return (NULL);

	if (s == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		s[i] = str[i];

	return (s);
}

