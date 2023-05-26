#include "shell.h"

void set_env(const char *name, const char *value);

int main(int __attribute__((unused))argc, char **argv)
{
	set_env(argv[2], argv[3]);
	return (0);
}

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
	new_var = malloc(strlen(name) + strlen(value) + 2);
	if (!new_var)
		return;
	while (env[len] != NULL)
		len++;

	/*for (char **ev = environ; *ev != NULL; ev++)
	{
		if (strcmp(*ev, name) == 0)
		{
			free(new_var);
			printf("%s FOUND\n", name);
			return;
		}
	}*/
	strcpy(new_var, name);
	strcat(new_var, "=");
	strcat(new_var, value);

	environ[len] = new_var;
	environ[len + 1] = NULL;
	free(new_var);
}
