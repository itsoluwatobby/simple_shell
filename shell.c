#include "shell.h"

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
	}
	return;
}