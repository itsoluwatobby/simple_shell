#include "shell.h"

/**
 * __exit - exits the shell
 * @av: the arguments vector
 * Return: void
 */

void __exit(char **av)
{
	int stat_code = 0;

	if (av[1] != NULL)
		stat_code = _atoi(av[1]);
	exit(stat_code);
}
