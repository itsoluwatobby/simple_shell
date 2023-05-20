#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: string to be measured
 *
 * Return: length of string
 */

int _strlen(char *s)
{
	if (*s == '\0')
		return (0);
	else
		return (1 + _strlen(s + 1));
}
