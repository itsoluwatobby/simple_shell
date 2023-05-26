#include "shell.h"

/**
 * execute - executes a command
 * @av: arguments to main
 * @argv: arguments to program
 * @env: environment variables
 *
 * Return: 0 if succesful and 1 otherwise
 */

void execute(char **av, char **argv, char **env)
{
	char *full_path;

	if (_strncmp(argv[0], "/bin", 4) == 0)
	{
		if (execve(argv[0], av, env) == -1)
		{
			perror(av[0]);
			free(argv);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		full_path = find_path(argv[0]);
		if (execve(full_path, argv, env) == -1)
		{
			perror(av[0]);
			free(argv);
			exit(EXIT_FAILURE);
		}
	}
}
