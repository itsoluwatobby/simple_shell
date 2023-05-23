#include "shell.h"

/**
 * execute - executes a command
 * @av: arguments to main
 * @argv: arguments to program
 * @i: argument position
 *
 * Return: 0 if succesful and 1 otherwise
 */

int execute(char **av, char **argv, int i)
{
	char *full_path;

	full_path = find_path(argv[i]);
	if (execve(full_path, argv, NULL) == -1)
	{
		printf("%s: No such directory", av[0]);
		free(argv);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
