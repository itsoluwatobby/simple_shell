#include "shell.h"

/**
 * _shell - simple shell functionality
 * @av : array of arguments
 * Return: 0
 */

void _shell(char **av)
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
		if (getline(&args, &size, stdin) == -1)
		{
			free(args);
			exit(EXIT_SUCCESS);
		}
		rm_newline(args);
		ac = count_args(args);
		argv = allocate_space(ac);
		argv[0] = args;
		id = fork();
		if (id == -1)
		{
			free(argv);
			free(args);
			exit(EXIT_FAILURE);
		}
		if (id == 0)
		{
			execute(av, argv);
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
}
