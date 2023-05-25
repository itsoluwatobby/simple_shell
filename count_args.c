#include "shell.h"

/**
 * count_args - count the number of arguments
 * @str: tokenized string
 * Return: number of arguments
 */

int count_args(char *str)
{
	int ac = 0;
	char temp[100], *tok;

	while (str[ac])
	{
		temp[ac] = str[ac];
		ac++;
	}
	temp[ac] = '\0';
	tok = strtok(temp, " \n");
	while (tok)
	{
		tok = strtok(NULL, " \n");
		ac++;
	}
	return (ac);
}
