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
		_free(command, args, NULL);
		__exit(command);
	}
	if (_strcmp(command[0], "env") == 0)
	{
		handle_env(env);
		_free(command, args, NULL);
		exit(EXIT_SUCCESS);
	}
	if (_strcmp(command[0], "setenv") == 0)
	{
		set_env(command[1], command[2]);
		_free(command, args, NULL);
		exit(EXIT_SUCCESS);
	}
}
