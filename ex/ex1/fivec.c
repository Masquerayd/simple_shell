#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - main function
 * Returns: always 0
 */
int main(void)
{
	pid_t fpid, cpid;
	int status;
	int count = 0;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	fpid = getpid();
	printf("fpid: %d\n", fpid);

	while (count < 5)
	{
		cpid = fork();
		wait(&status);
		if (cpid == 0)
		{
			printf("cpid: %d\n", getpid());
			execve(argv[0],argv,NULL);
			count = 5;

		}
		count++;
	}
	if( cpid != 0)
	{
		printf("code exited pid is : %d\n", getpid());
	}

	return (0);
}
