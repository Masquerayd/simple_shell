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
