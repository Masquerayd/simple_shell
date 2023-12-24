#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
/**
 * main - main function
 * @argc - the amount of arguments passed
 * @argv - an array of string of all the arguments passed
 * Returns: always 0
 */
int main(int argc, char **argv)
{
	int count = 0;
	struct stat st;

	while (count++ < argc -1)
	{
		if (stat(argv[count], &st) == 0)
		{
			printf("%s: file found\n", argv[count]);
		}
		else 
		{
			printf("%s: file not found\n", argv[count]);
		}
	}
	return (0);
}

