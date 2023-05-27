#include "shell.h"

void fork_process(pid_t id, char **argv, char **av, char *args, char **env)

/**
 * _shell - simple shell functionality
 * @av : array of arguments
 * @env: pointer to the environment var
 * Return: 0
 */

void _shell(char **av, char **env)
{
	char *args, **argv, *delim = " \n\t";
	pid_t id;
	size_t size;
	int ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			print_string("$ ");
		size = 0;
		if (get_line(&args, &size, STDIN_FILENO) == -1)
		{
			free(args);
			print_string("\n");
			exit(EXIT_SUCCESS);
		}
		ac = count_args(args);
		argv = allocate_space(ac);
		get_args(args, argv, delim);
		if (!args || !argv)
		{
			_free(argv, args, NULL);
			continue;
		}
		if ((!_strcmp(argv[0], "exit")) || (!_strcmp(argv[0], "env")) ||
				(!_strcmp(argv[0], "setenv")))
		{
			special_commands(argv, args, env);
			_free(argv, args, NULL);
		}
		id = fork();
		fork_process(id, argv, av, args, env);
	}
}

/**
 * fork_process - function that forks a process
 * @id: fork process id
 * @argv: 1st argument
 * @args: 2nd argument
 * @av: 3rd argument
 * @env: environment variable
 */

void fork_process(pid_t id, char **argv, char **av, char *args, char **env)
{
	if (id == -1)
	{
		_free(argv, args, env);

		exit(EXIT_FAILURE);
	}
	if (id == 0)
	{
		execute(av, argv, env);
		_free(argv, args, NULL);

	}
	else
	{
		wait(NULL);
		_free(argv, args, NULL);

	}
}
