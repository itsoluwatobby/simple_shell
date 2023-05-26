#include "shell.h"

void fork_process(char *args, char **argv, char **av, char **env, pid_t id);

/**
 * _shell - simple shell functionality
 * @av : array of arguments
 * @env: pointer to the environment var
 * Return: 0
 */

void _shell(char **av, char **env)
{
	char *args, **argv;
	int ac;
	pid_t id;
	size_t size;

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
		rm_newline(args);
		ac = count_args(args);
		argv = allocate_space(ac);
		argv[0] = args;
		if (special_commands(argv, env) != 0)
			fork_process(args, argv, av, env, id);
	}
}

/**
 * fork_process - function that forks a process
 * @argv: first argument
 * @args: 2nd argument
 * @av: 3rd argument
 * @id: fork id
 * @env: environment variable
 */

void fork_process(char *args, char **argv, char **av, char **env, pid_t id)
{
	id = fork();
	if (id == -1)
	{
		free(argv);
		free(args);
		exit(EXIT_FAILURE);
	}
	if (id == 0)
	{
		execute(av, argv, env);
		free(argv);
		free(args);
	}
	else
	{
		wait(NULL);
		free(args);
		free(argv);
	}
}
