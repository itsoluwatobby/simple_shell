#include "shell.h"

/**
 * handle_env - function that handles env command
 * @env: environment variable
 */

void handle_env(char **env)
{
	for (; *env != NULL; env++)
	{
		int length = 0;

		while ((*env)[length] != '\0')
			length++;
		write(STDOUT_FILENO, *env, length);
		write(STDOUT_FILENO, "\n", 1);
	}
}
