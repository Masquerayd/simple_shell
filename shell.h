#ifndef SIM_SHELL_H

#define SIM_SHELL_H

#define SH_MAX_SIZE 1024
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>

int _sh_print(char const *chars);
void _sh_prompt(void);
void shell_printf(const char *shell_inputs);
char *_getenv(const char *name);
void cmd_prompt(void);
#endif

