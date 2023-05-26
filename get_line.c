#include "shell.h"

/**
 * get_line - function that acts like getline function
 * @lineptr: agrguments parsed
 * @n: init size is 0
 * @fd: file descriptor
 * Return: 0 on succes, otherwise -1
 */

int get_line(char **lineptr, size_t *n, int fd)
{
	static int defaultSize = 120;
	ssize_t bufSize = 0;
	ssize_t bytes = 0;
	char *buffer = NULL, c;

	if (lineptr == NULL || n == NULL)
		return (-1);
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
			buffer = reallocate_memory(buffer, (bufSize * 2));
			*lineptr = buffer;
			*n = bufSize;
		}
		if (c == '\n')
			break;
	}
	buffer[bytes] = '\0';

	if (bytes == 0 && c == '\0')
		return (-1);
	return (bytes);
}
