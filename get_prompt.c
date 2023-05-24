#include "shell.h"

/**
 * get_prompt - creates prompt string
 *
 * Return: 0 success, otherwise 1.
 */

void get_prompt(void)
{
	char *prompt, *str, *tok, *host, *str_cpy;
	int i, j, k;

	prompt = get_memory(100);
	str = get_memory(100);
	host = get_memory(100);
	str_cpy = get_memory(100);
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
	add_to_prompt(prompt, ":~/", &i);
	j = k + 2;
	while (str[j])
	{
		prompt[i] = str[j];
		i++;
		j++;
	}
	free(str);
	add_to_prompt(prompt, "# ", &i);
	prompt[++i] = '\0';
	print_string(prompt);
	free(prompt);
}
