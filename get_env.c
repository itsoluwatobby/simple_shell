#include "shell.h"

/**
 * _get_env - gets the env variable
 * @arg: the env variable to get
 * @env: array of env variable
 * Return: pointer to env variable or NULL
 */

char *_get_env(char *arg, char **env)
{
	char *ret, *temp;
	int i = 0, len;

	len = _strlen(arg);
	while (env[i])
	{
		if (_strncmp(env[i], arg, len) == 0)
		{
			ret = env[i];
			break;
		}
		i++;
	}
	temp = _strtok(ret, "=");
	temp = _strtok(NULL, "=");
	return (temp);
}

