#include "shell.h"

/**
 * get_prompt - creates prompt string
 *
 * Return: 0 success, otherwise 1.
 */

int get_prompt(void)
{
	char *prompt, *str, *tok, *host, *str_cpy;
	int i, j, k;

	prompt = malloc(sizeof(char) * 100);
	str = malloc(sizeof(char) * 100);
	host = malloc(sizeof(char) * 100);
	str_cpy = malloc(sizeof(char) * 100);
	if (prompt == NULL || str == NULL || host == NULL || str_cpy == NULL)
	{
		free(prompt);
		free(str);
		free(host);
		free(str_cpy);
		return (1);
	}
	getcwd(str, 100);
	str_cpy = _strdup(str);
	tok = _strtok(str_cpy, "/");
	k = _strlen(tok);
	tok = _strtok(NULL, "/");
	free(str_cpy);
	i = _strlen(tok);
	_strcpy(prompt, "root");
	i += _strlen("root");
	prompt[i] = '@';
	i++;
	gethostname(host, 100);
	j = 0;
	while (host[j])
	{
		prompt[i] = host[j];
		i++;
		j++;
	}
	free(host);
	prompt[i] = ':';
	prompt[++i] = '~';
	prompt[++i] = '/';
	i++;
	j = k + 2;
	while (str[j])
	{
		prompt[i] = str[j];
		i++;
		j++;
	}
	free(str);
	prompt[i] = '#';
	prompt[++i] = ' ';
	prompt[++i] = '\0';
	print_string(prompt);
	free(prompt);
	return (0);
}
