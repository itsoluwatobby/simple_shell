#include "shell.h"

/**
 * _strcspn - returns the length of the segment of s1 not in s2
 * @s1: string 1
 * @s2: string 2
 * Return: the length of the segment
 */

int _strcspn(char *s1, char *s2)
{
	int res;

	if (s1 == NULL || s2 == NULL)
		return (0);
	res = 0;
	while (*s1)
	{
		if (_strchr(s2, *s1))
			return (res);
		s1++;
		res++;
	}
	return (res);
}
