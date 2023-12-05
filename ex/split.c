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
