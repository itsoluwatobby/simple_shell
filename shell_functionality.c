#include "shell.h"

/**
 * _shell - simple shell functionality
 * @av : array of arguments
 * Return: 0
 */

int _shell(char **av)
{
	char *args, **argv, *delim;
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
		
		printf("he=%s  al=%s", argv[0], argv[1]);

		special_commands(argv[0]);
		/*if (_strcmp(argv[1], "$?") || _strcmp(argv[1], "$$"))
			get_pid(argv[1]);*/
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
