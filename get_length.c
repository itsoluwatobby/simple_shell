#include "shell.h"

/**
 * get_len - returns the length of the argument vector
 * @av: the argument vector
 * Return: the length of the argument vector
 */

size_t get_len(char **av)
{
	size_t len = 0;
	int i = 1;

	while (av[i])
	{
		len += strlen(av[i]);
		i++;
	}
	return (len);
}
