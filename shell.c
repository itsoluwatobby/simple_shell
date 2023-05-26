#include "shell.h"

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
		if ((!_strcmp(argv[0], "exit")) || (!_strcmp(argv[0], "env")))
			special_commands(argv, args, env);
		/**
		 * if ((!_strcmp(argv[0], "cd")))
		{
			change_dir(argv, env);
			_free(argv, args, NULL);
			continue;
		}*/
		id = fork();
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
}
