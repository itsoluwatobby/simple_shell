#include "shell.h"

/**
 * handle_env - function that handles env command
 * @env: environment variables
 * Return: onsuccess (0)
 * @env: environment variables
 */

int handle_env(char **env)
{
	for (; *env != NULL; env++)
	{
		int length = 0;

		while ((*env)[length] != '\0')
			length++;
		write(STDOUT_FILENO, *env, length);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
