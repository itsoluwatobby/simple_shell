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
	char **argv, *tok, *args;
	int i = 0, j = 1, k = 1;
	size_t len = 0;

	(void) env;

	if (argc == 1)
		_shell(av);
	else
	{
		argv = malloc(sizeof(char *) * argc);
		if (!argv)
			return (1);
		while (av[k])
		{
			len += strlen(av[k]);
			k++;
		}
		len += argc;
		args = malloc(sizeof(char) * len);
		if (!arg)
			return (-1);
		while (av[j])
		{
			strcat(args, av[j]);
			strcat(args, " ");
			j++;
		}
		tok = strtok(args, " ");
		while (tok)
		{
			argv[i] = tok;
			tok = strtok(NULL, " ");
			i++;
		}
		argv[i] = NULL;
		if (execve(argv[1], av, NULL) == -1)
		{
			printf("%s: No such file or directory\n", av[0]);
			free(argv);
			return (1);
		}
	}
	free(argv);
	return (0);
}
