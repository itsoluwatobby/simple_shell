#include "shell.h"

/**
 * get_args - gets arguments from tokenized string
 * @args: tokenized string
 * @argv: array of arguments
 * @delim: the delimeter
 *
 * Return: array size
 */

int get_args(char *args, char **argv, char *delim)
{
	char *tok;
	char *temp;
	int i = 0;

	temp = _strdup(args);
	tok = strtok(temp, delim);
	while (tok)
	{
		argv[i] = _strdup(tok);
		i++;
		tok = strtok(NULL, delim);
	}
	argv[i] = NULL;
	return (i);
}
