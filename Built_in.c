#include "Prints.h"
#include "shell.h"

/**
 * shell_exit - Implement the exit built-in, that exits the shell
 * Return: nothing cuase it is void
 */
int shell_exit(void)
{
	char command[100];

	if (strcmp(command, "exit") == 0)
	{
	exit(0);
	}
	return (0);
}
