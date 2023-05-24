#include "shell.h"

/**
 * _exit - exits the shell
 * @av: the arguments vector
 * @env: the environment vector
 * Return: void
 */

void _exit(char **av, char **env)
{
	int stat_code = 0;

	if (av[1] != NULL)
	{
		stat_code = _atoi(av[1]);
		free_vector(av);
		free(av);
		free_vector(env);
		free(env);
		exit(stat_code);
	}
	free_vector(av);
	free(av);
	free_vector(env);
	free(env);
	exit(stat_code);

}


