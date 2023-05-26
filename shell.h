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

extern char **environ;

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
int count_args(char *str);
char **allocate_space(int size);
void _shell(char **av, char **env);
void execute(char **av, char **argv, char **env);
void rm_newline(char *str);
char *find_path(char *command);
int special_commands(char **command, char **env);
int get_line(char **lineptr, size_t *n, int fd);
char *reallocate_memory(char *buf, int bufs);
char *get_memory(int bufs);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void handle_env(void);

#endif /* SHELL_H */
