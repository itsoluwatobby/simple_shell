#include "shell.h"

/**
 * _setenv - function that sets an environment variable
 * @args: variable to set
 */

void _setenv(char *name, char *value)
{
	if (setenv(name, value, 1) == -1)
	{
		perror("Error setting env");
		exit(EXIT_FAILURE);
	}
}

/**
 * check_var - function that splits the incoming string into name, value
 * @argv: parsed string
 */

void check_var(char *argv)
{
	char *token, *name = NULL, *value = NULL, *delimiter = "=";

	token = _strtok(argv, delimiter);
	name = token;
	token = _strtok(NULL, delimiter);
	value = token;
	if (name == NULL || value == NULL)
	{
		perror("Error: Invalid argument.");
		exit(EXIT_FAILURE);
	}
	_setenv(name, value);

	printf("name=%s  val=%s", name, value);
}

