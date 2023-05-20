#include "shell.h"

/**
 * main - starts the simple shell
 * @argc: argument count
 * @av: argument vector
 * @env: environment vector
 * Return: 0
 */

int main(int argc, char **av, char **env)
{
	char **argv, *delim, *args;
	int len = 0;

	(void) env;

	if (argc == 1)
		_shell(av);
	else
	{
		argv = allocate_space(argc);
		len = get_len(av);
		len += argc;
		args = malloc(sizeof(char) * len);
		if (!args)
			exit(EXIT_FAILURE);
		tokenize(args, av);
		delim = " ";
		get_args(args, argv, delim);
		execute(av, argv, 1);
	}
	free(argv);
	return (0);
}
