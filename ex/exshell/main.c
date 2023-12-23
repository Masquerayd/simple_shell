#include "shell.h"

/**
 * main - main function
 * Return: alwyas 0
 */
int main(void)
{
	char str[] = "Hello why is this not working";
	char **array;

	shell();
	
	array = splitstr(str);
	free(array);
	return (0);
}
