#include "shell.h"

/**
 * _shell - simple shell functionality
 * @av : array of arguments
 * @env: environment
 * Return: 0
 */

int _shell(char **av)
{
	char *args, *tmp, **argv, *tok;
	int i = 0, ac = 0;
	pid_t child_id;
	size_t size = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		if (getline(&args, &size, stdin) == -1)
			return (1);
		tmp = strdup(args);
		tok = strtok(tmp, " \n");
		if (!tok)
			return (1);
		while (tok)
		{
			tok = strtok(NULL, " \n");
			ac++;
		}
		argv = malloc(sizeof(char *) * (ac + 1));
		if (!argv)
			return (1);
		tok = strtok(args, " \n");
		while (tok)
		{
			argv[i] = strdup(tok);
			tok = strtok(NULL, " \n");
			i++;
		}
		argv[i] = NULL;
		child_id = fork();
		if (child_id == -1)
		{
			free(argv);
			return (1);
		}
		if (child_id == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				printf("%s: No such file or directory\n", av[0]);
				free(argv);
				return (1);
			}
		}
		else
		{
			wait(NULL);
			free(argv);
		}
	}
	return (0);
}

