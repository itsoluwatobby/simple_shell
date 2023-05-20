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

int _shell(char **av);
int count_args(char *str);
char **allocate_space(int size);
int get_args(char *args, char **argv, char *delim);
size_t get_len(char **av);
int tokenize(char *args, char **av);
int execute(char **av, char **argv, int i);
char *find_path(char *command);
void handle_env(void);
int get_line(char **lineptr, size_t *n, int fd);
char *get_memory(int bufs);
char *reallocate_memory(char *buf, int bufs);
int _putchar(char c);
int print_string(char *str);
int _strlen(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int get_prompt(void);

#endif /* SHELL_H */
