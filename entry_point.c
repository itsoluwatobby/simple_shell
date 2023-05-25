#include "shell.h"
#include <mcheck.h>
/**
 * main - starts the simple shell
 * @argc: argument count
 * @av: argument vector
 * @env: environment vector
 * Return: 0
 */

int main(int argc, char **av, char **env)
{
	(void) env;

	if (argc == 1)
		_shell(av);
	return (0);
}
