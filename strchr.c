#include "shell.h"

/**
 * _strchr - locates a character in a string
 * @s: string
 * @c: character to locate
 *
 * Return: pointer to the first occurrence of the character c
 * or NULL if the character is not found
 */

char *_strchr(char *s, char c)
{
	int i;

	i = 0;

	while (1)
	{
		if (s[i] == c)
			return (s + i);
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
}
