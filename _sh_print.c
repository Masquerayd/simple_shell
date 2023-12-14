#include "shell.h"

/**
 * _sh_print - A function that print characters.
 *
 * @c: character to be printed.
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _sh_print(char const *chars)
{
	return (write(1, chars, strlen(chars)));
}
