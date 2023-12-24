#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

ssize_t shell(void);
char **splitstr(char *string);
int checkcom(char **arg);

#endif
