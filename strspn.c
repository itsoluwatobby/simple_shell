#include "shell.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: string
 * @accept: string
 *
 * Return: number of bytes in s
 */

unsigned int _strspn(char *s, char *accept)
{
	int i, j;
	unsigned int count, match;

	count = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		match = 0;

		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				match = 1;
				break;
			}
		}

		if (!match)
		{
			break;
		}
		else
		{
			count++;
		}
	}
	return (count);
}
