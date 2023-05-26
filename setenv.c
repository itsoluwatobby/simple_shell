#include "shell.h"

/**
 * set_env - function that sets the env variable
 * @name: variable name
 * @value: value
 */

void set_env(const char *name, const char *value)
{
	char *new_var = NULL, **env = environ;
	ssize_t len = 0;

	if (env == NULL)
		return;
	if (name == NULL || value == NULL)
	{
		perror("Error syntax! Enter setenv <name> <value>");
		exit(EXIT_FAILURE);
	}
	new_var = malloc(strlen(name) + strlen(value) + 2);
	if (!new_var)
		return;
	while (env[len] != NULL)
		len++;
	strcpy(new_var, name);
	strcat(new_var, "=");
	strcat(new_var, value);

	while (*env != NULL && strcmp(*env, name) != 0)
		env++;
	if (*env != NULL)
	{
		*env = new_var;
		environ[len + 1] = NULL;
		free(new_var);
		return;
	}
	environ[len] = _strdup(new_var);
	environ[len + 1] = NULL;
	/*free(new_var);*/
}
