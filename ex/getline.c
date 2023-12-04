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
	int i;

	*size = 0;
	
	printf("$ ");
	string = (char **)malloc(10000);
	while ((number = getline(&string, &size, stdin)) != -1)
	{
		printf("%s\n",*string[i]);
		printf("%ld\n",number);
		i++;
	}
	return (0);
}


