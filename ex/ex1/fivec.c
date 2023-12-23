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
	pid_t process;
	int status;

	fpid = getpid();
	cpid = getpid();

	while (cpid <= fpid + 2)
	{
		process = fork();
		cpid = getpid();
		if ( cpid > fpid + 2)
		{
			wait(&status);
		}
		
	}

	if (process == -1)
	{
		printf(" Fork process failed");
	}
	
	if (process == 0)
	{
		cpid = getpid();
		fpid = getppid();
		printf("In child pid: %u and parent pid %u\n", cpid, fpid);

	}
	else
	{
		wait(&status);
		printf("father process %u\n", fpid);
	}
	printf("ending process: %u\n",cpid);

	return (0);
}
