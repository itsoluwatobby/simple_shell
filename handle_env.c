#include "shell.h"

/**
 * handle_env - function that handles env command
 */

void handle_env(void)
{
	extern char **environ;
	char **env = environ;

	for (; *env != NULL; env++)
	{
		int length = 0;

		while ((*env)[length] != '\0')
			length++;
		write(STDOUT_FILENO, *env, length);
		write(STDOUT_FILENO, "\n", 1);
	}
}
