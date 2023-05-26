#include "shell.h"

/**
 * _free - frees memory
 * @av: array of pointers to chars
 * @args: array of chars
 * @env: pointer to the environment
 * Return: void
 */

void _free(char **av, char *args, char **env)
{
	if (av)
		free(av);
	if (args)
		free(args);
	if (env)
		free(env);
}
