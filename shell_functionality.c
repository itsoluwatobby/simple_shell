#include "shell.h"

/**
 * _shell - simple shell functionality
 * @av : array of arguments
 * Return: 0
 */

int _shell(char **av)
{
	char *args, **argv, *delim, **envptr;
	int ac = 0;
	pid_t child_id;
	size_t size = 0;

	envptr = allocate_env();
	while (1)
	{
		if (isatty(STDIN_FILENO))
			get_prompt();
		if (get_line(&args, &size, STDIN_FILENO) == -1)
		{
			free(envptr);
			perror("Shell Exited!");
			exit(EXIT_SUCCESS);
		}
		ac = count_args(args);
		argv = allocate_space(ac);
		delim = " \n";
		get_args(args, argv, delim);
		special_commands(argv, envptr);
		child_id = fork();
		if (child_id == -1)
		{
			free_vector(argv);
			free_vector(envptr);
			exit(EXIT_FAILURE);
		}
		if (child_id == 0)
		{
			execute(av, argv, 0);
		}
		else
		{
			wait(NULL);
			free_vector(argv);
		}
	}
	free_vector(envptr);
	return (0);
}
