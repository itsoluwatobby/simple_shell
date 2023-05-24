#include "shell.h"

/**
 * _shell - simple shell functionality
 * @av : array of arguments
 * Return: 0
 */

int _shell(char **av)
{
	char *args, **argv, *delim, **env = environ;
	int ac = 0;
	pid_t child_id;
	size_t size = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			get_prompt();
		if (get_line(&args, &size, STDIN_FILENO) == -1)
		{
			perror("Shell Exited!");
			exit(EXIT_FAILURE);
		}
		ac = count_args(args);
		argv = allocate_space(ac);
		delim = " \n";
		get_args(args, argv, delim);
	
		special_commands(argv[0]);
		if (_strcmp(argv[0], "cd") == 0)
			change_dir(argv, env);
		child_id = fork();
		if (child_id == -1)
		{
			free(argv);
			exit(EXIT_FAILURE);
		}
		if (child_id == 0)
		{
			execute(av, argv, 0);
		}
		else
		{
			wait(NULL);
			free(argv);
		}
	}
	return (0);
}
