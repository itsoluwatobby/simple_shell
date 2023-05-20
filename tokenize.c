#include "shell.h"

/**
 * tokenize - tokenize a string
 * @args: pointer to result string
 * @av: strings to tokenize
 * Return: 0
 */

int tokenize(char *args, char **av)
{
	int i = 1;

	while (av[i])
	{
		_strcat(args, av[i]);
		_strcat(args, " ");
		i++;
	}
	return (i);
}
