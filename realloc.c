#include "shell.h"
#include <stdlib.h>

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to previously allocated memory block
 * @old_size: size of previously allocated memory block
 * @new_size: size of newly allocated memory block
 *
 * Return: pointer to newly allocated memory block
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	char *tmp_ptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
		return (new_ptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	tmp_ptr = malloc(new_size);
	if (tmp_ptr == NULL)
		return (NULL);
	for (i = 0; i < old_size; i++)
		tmp_ptr[i] = ((char *)ptr)[i];
	free(ptr);
	new_ptr = (void *)tmp_ptr;
	return (new_ptr);
}
