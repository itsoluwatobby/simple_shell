#include "shell.h"

/**
 * execute - executes a command
 * @av: arguments to main
 * @argv: arguments to program
 * @env: environment variables
 * Return: 0 if succesful and 1 otherwise
 */

void execute(char **av, char **argv, char **env)
{
	if (execve(argv[0], av, env) == -1)
	{
		perror(av[0]);
		free(argv);
		exit(EXIT_FAILURE);
	}
}
