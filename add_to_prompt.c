#include "shell.h"

/**
 * add_to_prompt - add a string to the prompt
 * @prompt: prompt string
 * @str: string to add to the prompt
 * @i: starting index of prompt to fill
 * Return: the updated value of i
 */

void add_to_prompt(char *prompt, char *str, int *i)
{
	int j = 0;

	while (str[j] != '\0')
	{
		prompt[*i] = str[j];
		(*i)++;
		j++;
	}
}
