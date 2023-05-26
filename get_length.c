#include "shell.h"

/**
 * get_len - returns the length of the argument vector
 * @av: the argument vector
 * Return: the length of the argument vector
 */

int get_len(char **av)
{
	int i = 1, len = 0;

	while (av[i])
	{
		len += _strlen(av[i]);
		i++;
	}
	return (len);
}
