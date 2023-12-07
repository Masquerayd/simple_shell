#include <stdio.h>
#include <unistd.h>

/**
 * main - main execve example
 * Returns: always 0
 */
int main (void)
{
	char *argv[] = {"/bin/ls", "-l"	, "/root/simple_shell/ex", NULL};

	printf("before execve\n");
	if (execve(argv[0],argv, NULL) == -1)
	{
		perror("Error:");
	}
	return (0);
}
