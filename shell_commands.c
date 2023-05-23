#include "shell.h"

/**
 * special_commands - function that checks for some specific commands
 * @command: command to check
 * Return: onSuccess (0)
 */

void special_commands(char *command)
{
	if (_strcmp(command, "exit") == 0)
	{
		free(command);
		exit(EXIT_SUCCESS);
	}
	if (_strcmp(command, "env") == 0)
	{
		handle_env();
		exit(98);
	}
}
