#include "shell.h"

/**
 * splitstr - splits a string and puts it into an array
 * @string: The string that will be split
 * Return: The array that has the string in the array
 */
char **splitstr(char *string)
{
	char **array;
	char *stringb;
	int count = 0;

	array = (char **)malloc(10000);
	stringb = strtok(string, "\n");
	array[count] = strtok(stringb, " ");
	while (array[count++] != NULL)
	{
		array[count] = strtok(NULL, " ");
	}
	array[count] = NULL;

	return (array);
}
