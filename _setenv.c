#include "shell.h"

/**
 * _setenv - function that sets an environment variable
 * @args: variable to set
 */

int _setenv(char *args)
{
	char *token, *name = NULL, *value = NULL, *delimiter = "=";
	/*int success;*/

	token = strtok(args, delimiter);
	while (token != NULL)
	{
		if (name == NULL)
			name = strdup(token);
		else
			value = strdup(token);

		token = strtok(NULL, delimiter);
	}
	if (name == NULL || value == NULL)
	{
		perror("Error: Invalid argument.\n");
		return -1;
	}

	setenv(name, value, 0);
	/*if (success != 0)
	{
		perror("Error setting env");
		return(-1);
	}*/
	printf("%s set\n", value);
	printf("%s set\n", name);
	return (0);
}

int main(int argc, char **argv)
{
	char **new;
	int i = 0;

	new = allocate_space(argc - 1);

	for (i = 1; i < argc; i++)
	{
		new[i - 1] = malloc(strlen(argv[i]) + 1);
		if (new[i - 1] == NULL)
		{
			printf("Error: Failed to allocate memory for new string.\n");
			return 1;
		}
		strcpy(new[i - 1], argv[i]);
	}
	_setenv(new[1]);
	free(new);
	return (0);
}
