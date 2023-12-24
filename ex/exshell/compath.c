#include <stdio.h>
#include "shell.h"



/**
 * checkcom - checks and runs the command passed as argument
 * @arg: The argument that will be checked
 */

int checkcom(char **arg)
{
	int count = 0;
	int num, status;
	pid_t newprogram;

	newprogram = fork();
	wait(&status);
	if (newprogram == 0)
	{
		num = execve(arg[0], arg, NULL);
	}
	if(num == -1)
	{
		printf("Error from input arg\n");
	}
	return (count);
}
				
	

