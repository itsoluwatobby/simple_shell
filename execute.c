#include "shell.h"

/**
 * execute - executes a command
 * @av: arguments to main
 * @argv: arguments to program
 *
 * Return: 0 if succesful and 1 otherwise
 */

void execute(char **av, char **argv)
{
	if (execve(argv[0], av, NULL) == -1)
	{
		perror(av[0]);
		free(argv);
		exit(EXIT_FAILURE);
	}
}
