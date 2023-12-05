#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - the main function 
 * Return: always 0
 */
int main (void)
{
	char *string = NULL;
	size_t size = 0;
      	ssize_t number;

	printf("$ ");
	while ((number = getline(&string, &size, stdin)) != -1)
	{
		printf("%s",string);
		break;
	}
	free(string);
	return (0);
}
