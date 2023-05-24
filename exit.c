#include "shell.h"

/**
 * __exit - exits the shell
 * @av: the arguments vector
 * @env: the environment vector
 * Return: void
 */

void __exit(char **av, char **env)
{
	int stat_code = 0;

	if (av[1] != NULL)
	{
		stat_code = _atoi(av[1]);
		free_vector(av);
		free_vector(env);
		exit(stat_code);
	}
	free_vector(av);
	free_vector(env);
	exit(stat_code);

}


