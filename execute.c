#include "shell.h"

/**
 * execute - executes a command
 * @av: arguments to main
 * @argv: arguments to program
 *
 * Return: 0 if succesful and 1 otherwise
 */

int execute(char **av, char **argv, int i)
{
	if (execve(argv[i], argv, NULL) == -1)
	{
		printf("%s: No such file or directory\n", av[0]);
		free(argv);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
