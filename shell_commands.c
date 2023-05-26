#include "shell.h"

/**
 * special_commands - function that checks for some specific commands
 * @command: command to check
 * @args: the arguments returned from getline
 * @env: the environment
 * Return: void
 */

void special_commands(char **command, char *args, char **env)
{
	if (_strcmp(command[0], "exit") == 0)
	{
		_free(command, args, env);
		__exit(command);
	}
	if (_strcmp(command[0], "env") == 0)
	{
		handle_env();
		_free(command, args, env);
		exit(EXIT_SUCCESS);
	}
}
