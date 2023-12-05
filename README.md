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


