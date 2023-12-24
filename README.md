# Simple Shell project

## PID & PPID

When executing a program a process is creaated and this process has a unique ID. This process IF is used by many system call and functions to interact with and manipulate processes. In order to retrieve the current process ID, you can use the system call `getpid` (man 2 `getpid`):

1. `getpid()` - returns the provess ID (PID) of the calling process.
1. `gitppid()` - returns the process ID of the parent of the calling process.

below is a simple example of how to obtain the *PID* of the calling function and the *PID* of the parent.

```c
#include <stdio.h>
#include <unistd.h>

/**
 * main - gives the process ID of an executiing process
 * Return: always 0
 */
int main(void)
{
        pid_t my_pid;

        my_pid = getpid();
        printf("%u\n", my_pid);
        my_pid = getppid();
        printf("%u\n", my_pid);

        return (0);
}
```
**NOTE:** everytime you run the program above a new process is created and a new ID is created.

Each process has a parent which is the process that created it, it remains the same but the process ID changes

## Arguments

Agruments in the command line can be passed through the main functions. In order to do this the main function would have to be declared this way, `int main( int ac, char **av);`.

- av is `NULL` terminated array of strings.
- ac is the number of items in `av`.

`av[0]` usually contains the name used to invoke the current program. `av[1]` is the first argument of the program. `av[2]` the second, and so on.

here is an example of an argument program
```c
# include <stdio.h>

/**
 * main - main function
 * Return: always 0
 */
int main( int ac, char ** av)
{

        int i;

        (void) ac;

        for (i = 0; av[i] != 0x0; i++)
        {
                printf("%s\n", av[i]);
        }
        return 0;
}
```

## Read line
when working with shell a program sometimes needs an input from the user inorder to determine a desired outcome , this can be implemented with the use of `getline()`(check `man 3 getline`).

- geline - stores the address of a  whole input line into a buffer with a pointer called `lineptr`.the buffere is terminated with a `NULL` character.

the code for read a line and printing it is below

```c
#include "shell.h"

/**
 * shell - that will basically start a program and wait for a user input and act based on that
 * Return: always 0;
 */
ssize_t shell(void)
{
        char *lineptr = NULL;
        size_t size = 0;
        ssize_t numchars;

        while(1)
        {
                printf("$ ");
                numchars = getline(&lineptr, &size, stdin);
                if (numchars == -1)
                {
                        printf("error\n");
                        free(lineptr);
                        return (-1);
                }
                printf("your input is %s", lineptr);
                lineptr = NULL;
        }
        free(lineptr);

        return (numchars);
}
```
You can also pass a **string** as an argument , and we may need to split the string into different parameters. this can be done with the use of `strtok`. 

**Strtok()**

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * splitstr - splits a str
 * @str: the string it will split
 * @delim: the delimiter that will be used to split the string
 */
char **splitstr(char *str, char *delim)
{
        char **array;
        int count = 0;


        array = (char **)malloc(10000);
        array[count] = strtok(str, delim);

        while (array[count] != NULL)
        {
                array[++count] = strtok(NULL, " ");
        }
        return (array);
}


/**
 * main - the main function
 * Return: always zero
 */
int main(void)
{
        char str[] = "hello I am about to split the string";
        char **array;
        int count = 0;

        array = splitstr(str, " ");

        while(array[count] != NULL)
        {
                printf("%s\n", array[count++]);
        }
        free(array);
        return 0;
}
```
## Executing a program
The system call `execve` allows a process to execute another program (man 2 `evecve`). Note that this system call load a new program into the current system memory replacing the previous one. here is an example of how to call an execve function. Its better to start another child process and run the `execve` function through it, as it terminates the program or replaces it when it executes.

'''c
#include <unistd.h>

       int execve(const char *pathname, char *const _Nullable argv[],
                  char *const _Nullable envp[]);
'''

here is a practical example of how to use the code 

```c
#include <stdio.h>
#include <unistd.h>
/**
 * main - main execve example
 * Returns: always 0
 */
int main (void)
{
	char *argv[] = {"/bin/ls", "-l" , "/root/simple_shell/ex", NULL};
	printf("before execve\n");
	if (execve(argv[0],argv, NULL) == -1)
	{
		perror("Error:");
        }
        return (0);
}
```

## Creating a New process

The system call , called fork (man 2 `fork), creates a new process that is similar to the parent process.Once the `fork` system call returns , two processs continue to run from the same point , but the first process will be completed then the second one will start from that point which fork was called

here is an example showing how the system call fork works

```c
#include <stdio.h>
#include <unistd.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid;
    pid_t pid;

    printf("Before fork\n");
    pid = fork();
    if (pid == -1)
    {
        perror("Error:");
        return (1);
    }
    printf("After fork\n");
    my_pid = getpid();
    printf("My pid is %u\n", my_pid);
    return (0);
}
```

Output of code is 

```
julien@ubuntu:~/c/shell$ ./fork
Before fork
After fork
My pid is 4819
julien@ubuntu:~/c/shell$ After fork
My pid is 4820
```
There is a simple way to check if the process running is the child or the father , we know that the child will return 0 , where as the father process will return the PID of the parent

## Wait 

The system call `wait` suspends the process o fthe calling process until, one of its child terminates. you can check (`man 2 wait`) for more info.

the code below shows an example of how the parent process which runs first wait for the child process to execute then it runs the parent process

```c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error:");
        return (1);
    }
    if (child_pid == 0)
    {
        printf("Wait for me, wait for me\n");
        sleep(3);
    }
    else
    {
        wait(&status);
        printf("Oh, it's all better now\n");
    }
    return (0);
}
```

output of the code above

```
julien@ubuntu:~/c/shell$ gcc -Wall -Wextra -Werror -pedantic wait.c -o wait
julien@ubuntu:~/c/shell$ ./wait
Wait for me, wait for me
Oh, it's all better now
julien@ubuntu:~/c/shell$
```
## stat()

This function returns information about a file, in the buffer pointed to by statbuf, If the file is found `stat` returns a 0. On error , -1 is returned.

```c
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * main - stat example
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    unsigned int i;
    struct stat st;

    if (ac < 2)
    {
        printf("Usage: %s path_to_file ...\n", av[0]);
        return (1);
    }
    i = 1;
    while (av[i])
    {
        printf("%s:", av[i]);
        if (stat(av[i], &st) == 0)
        {
            printf(" FOUND\n");
        }
        else
        {
            printf(" NOT FOUND\n");
        }
        i++;
    }
    return (0);
}
```
The output

```
ubuntu:~/c/shell$ ./stat ls /bin/ls /usr/bin/ls
ls: NOT FOUND
/bin/ls: FOUND
/usr/bin/ls: NOT FOUND
ubuntu:~/c/shell$ 
```
