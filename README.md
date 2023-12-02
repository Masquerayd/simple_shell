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
