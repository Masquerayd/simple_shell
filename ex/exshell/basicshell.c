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
	char **array;

	while(1)
	{
		printf("$ ");
		numchars = getline(&lineptr, &size, stdin);
		array = (char **)malloc(10000);
		if (numchars == -1)
		{
			printf("The program closed\n");
			free(lineptr);
			free(array);
			return (-1);
		}
		array = splitstr(lineptr);
		checkcom(array);
		lineptr = NULL;
	}

	return (numchars);
}
