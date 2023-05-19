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
void get_line(char **lineptr, size_t *n, int fd);
char *get_memory(int bufs);
char *reallocate_memory(char *buf, int bufs);

#endif /* SHELL_H */
