#include "shell.h"

/**
 * get_line - function that acts like getline function
 * @lineptr: agrguments parsed
 * @n: init size is 0
 * @fd: file descriptor
 * Return: bytes read
 */

void get_line(char **lineptr, size_t *n, int fd)
{
	static int defaultSize = 120;

	ssize_t bufSize = 0;
	ssize_t bytes = 0;
	char *buffer = NULL, c;

	if (lineptr == NULL || n == NULL)
		return;
	if (*lineptr == NULL || *n == 0)
	{
		bufSize = defaultSize;
		buffer = get_memory(bufSize);
		*lineptr = buffer;
		*n = bufSize;
	}
	else
	{
		buffer = *lineptr;
		bufSize = *n;
	}
	while (read(fd, &c, 1) > 0)
	{
		buffer[bytes] = c;
		bytes++;

		if (bytes >= bufSize)
		{
			bufSize = bufSize * 2;
			buffer = reallocate_memory(buffer, bufSize);
			*lineptr = buffer;
			*n = bufSize;
		}
		if (c == '\n')
			break;
	}
	buffer[bytes] = '\0';

	write(STDOUT_FILENO, *lineptr, bytes);
}

/**
 * main - runs the custom get_line function
 * Return: onSuccess 0
*/

int main(void)
{
	char *line_entry = NULL;
	size_t size = 0;

	get_line(&line_entry, &size, STDIN_FILENO);

	free(line_entry);
	return (0);
}
