#include "shell.h"

/**
 * get_pid - function that get the process id
 * @command: command given to return pid
 * Return: process ID
 */

pid_t get_pid(char *command)
{
	pid_t processId;
	int status;

	if (_strcmp(command, "$?"))
		processId = waitpid(1, &status, 0);
	else  if (_strcmp(command, "$$"))
		processId = getppid();

	printf("%d\n", processId);
	return (processId);
}
