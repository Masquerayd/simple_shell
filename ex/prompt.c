# include <stdio.h>

/**
 * main - main function
 * Return: always 0
 */
int main( int ac, char ** av)
{

	int i;

	(void) ac;

	for (i = 0; av[i] != 0x0; i++)
	{
		printf("%s\n", av[i]);
	}
	return 0;
}
