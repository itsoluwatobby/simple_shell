#include "shell.h"

/**
 * change_dir - changes the directory
 * @av: arguments
 * @env: the environment variables
 * Return: 0 or -1 if not sucessful
 */

int change_dir(char **av, char **env)
{
	char *dir, *curr;
	int i = 0;

	dir = _get_env("PWD", env);
	if (av[1] != NULL)
	{
		if (av[1][0] == '-')
		{
			curr = _get_env("OLDPWD", env);
		}
		else
		{
			curr = _strdup(av[1]);
		}
	}
	else
	{
		curr = _get_env("HOME", env);
	}
	i = chdir(curr);
	if (i != -1)
	{
		_setenv("OLDPWD", dir, env);
		_setenv("PWD", curr, env);
	}
	return (i);
}


