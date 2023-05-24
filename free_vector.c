#include "shell.h"

/**
 * free_vector - frees a 2d array
 * @arr: the 2d array to be freed
 *
 * Return: void
 */

void free_vector(char **arr)
{
	int i = 0;

	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
}
