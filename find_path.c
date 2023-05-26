#include "shell.h"

void build_path(char *full_path, char *token, char *command);

/**
 * find_path - function that get a command directory path
 * @command: given command
 * Return: a pointer to the path
 */
char *find_path(char *command)
{
	char *copy, *command_path, *token, *delimiter = ":", *full_path;
	int commandLength = _strlen(command), token_length = 0;
	struct stat buffer;

	command_path = getenv("PATH");
	if (command_path == NULL)
		return (NULL);
	copy = _strdup(command_path);
	token = _strtok(copy, delimiter);
	while (token != NULL)
	{
		token_length = _strlen(token);
		full_path = malloc(token_length + commandLength + 2);
		if (full_path == NULL)
		{
			free(copy);
			return (NULL);
		}
		build_path(full_path, token, command);
		if (stat(full_path, &buffer) == 0)
		{
			free(copy);
			return (full_path);
		}
		free(full_path);
		token = _strtok(NULL, delimiter);
	}
	free(copy);
	if (stat(command, &buffer) == 0)
	{
		full_path = malloc(commandLength + 1);
		if (full_path == NULL)
			return (NULL);
		_strcpy(full_path, command);
		return (full_path);
	}
	free(full_path);
	return (NULL);
}

/**
 * build_path - function that builds a path
 * @full_path: path
 * @token: 2nd argument
 * @command: given command
 */

void build_path(char *full_path, char *token, char *command)
{
	_strcpy(full_path, token);
	_strcat(full_path, "/");
	_strcat(full_path, command);
	_strcat(full_path, "\0");
}
