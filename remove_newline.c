#include "shell.h"

/**
 * rm_newline - removes newline from a string
 * @str: string to remove newline from
 */

void rm_newline(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '\n')
			str[i] = '\0';
	}
}
