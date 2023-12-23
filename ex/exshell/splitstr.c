#include "shell.h"

/**
 * splitstr - splits a string and puts it into an array
 * @str: The string that will be split 
 * Return: The array that has the string in the array
 */
char **splitstr(char *string)
{
	char **array;
	int count = 0;

	array = (char **)malloc(10000);
	array[count] = strtok(string, " ");
	while(array[count++] != NULL)
	{
		array[count] = strtok(NULL, " ");
	}
	return (array);
}
