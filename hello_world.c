#include <unistd.h>

/**
 * main - prints hello world
 * Return: onSuccess (1)
 */

int main(void)
{
	int i = 0;
	char *message = "Hello world";
	int newLine = '\n';

	while (message[i])
	{
		write(1, &message[i], 1);
		i++;
	}
	write(1, &newLine, 1);

	return (0);
}
