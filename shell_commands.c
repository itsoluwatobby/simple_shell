#include "shell.h"

/**
 * special_commands - function that checks for some specific commands
 * @command: command to check
 * @env: the environment
 * Return: void
 */

void special_commands(char **command, char **env)
{
	if (_strcmp(command[0], "exit") == 0)
	{
		_exit(command, env);
	}
	if (_strcmp(command[0], "env") == 0)
	{
		handle_env();
		exit(98);
	}
	if (_strcmp(command[0], "cd") == 0)
		change_dir(command, env);
}
