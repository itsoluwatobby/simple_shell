#include "shell.h"

/**
 * allocate_env - allocates memory for the env
 *
 * Return: pointer to the allocated block of memory
 */

char **allocate_env(void)
{
	int i = 0;
	char **ptr;

	while (environ[i])
		i++;
	ptr = allocate_space(i);
	for (i = 0; environ[i]; i++)
		ptr[i] = _strdup(environ[i]);
	environ[i] = NULL;

	return (ptr);
}



