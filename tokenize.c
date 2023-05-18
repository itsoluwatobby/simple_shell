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
		strcat(args, av[i]);
		strcat(args, " ");
		i++;
	}
	return (i);
}
