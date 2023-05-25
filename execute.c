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
		print_string(av[0]);
		print_string(": No such file or directory\n");
		free(argv);
		exit(EXIT_FAILURE);
	}
	/*print_string("FULL PATH HERE");*/
	free(full_path);
	exit(EXIT_SUCCESS);
}
