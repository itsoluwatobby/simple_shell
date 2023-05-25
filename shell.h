#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

int _putchar(char c);
int print_string(char *str);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
unsigned int _strspn(char *s, char *accept);
char *_strchr(char *s, char c);
int _strcspn(char *s1, char *s2);
int _strncmp(char *str1, char *str2, int c);
int _atoi(char *s);
char *_strstr(char *haystack, char *needle);

#endif /* SHELL_H */
