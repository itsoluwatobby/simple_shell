#include "shell.h"

/**
 * print_string - prints a string to stdout
 * @str: string to print
 * Return: number of characters printed
 */

int print_string(char *str)
{
	int i = 0;

	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}
