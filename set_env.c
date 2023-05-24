#include "shell.h"

/**
 * _setenv - sets or modifies an env variable
 * @key: the env variable name
 * @value: the value to be set
 * @env: the environment
 *
 * Return: 0 if succesful
 */

int _setenv(char *key, char *value, char **env)
{
	int i = 0, j = 0, len1, len2, state = 0;
	char *var;

	len1 = _strlen(key);
	len2 = _strlen(value);
	var = get_memory(sizeof(char) * (len1 + len2 + 2));
	while (key[i])
	{
		var[i] = key[i];
		i++;
	}
	var[i] = '=';
	i++;
	while (value[j])
	{
		var[i] = value[j];
		i++;
		j++;
	}
	var[i] = '\0';
	for (i = 0; env[i]; i++)
	{
		if (_strncmp(env[i], key, len1) == 0)
		{
			free(env[i]);
			env[i] = _strdup(var);
			state = 1;
			break;
		}
	}
	if (state == 0)
	{
		free(env[i]);
		env[i] = _strdup(var);
		env[i + 1] = NULL;
	}
	free(var);
	return (0);
}
