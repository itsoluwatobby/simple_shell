#include "shell.h"

/**
 * free_vec - frees an array of pointers to strings
 * @vec: the array
 * Return: void
 */

void free_vec(char **vec)
{
	int i = 0;

	while (vec[i])
	{
		free(vec[i]);
			i++;
	}
	free(vec);
}
