#include "shell.h"
#include "Prints.h"

/**
 * mainc - Entry point for the shell program.
 * @ac: Argument count.
 * @av: Argument vector.
 *
 * Return: 0 on success, 1 on error.
 */
int mainc(int ac, char **av)
{
    info_t info[] = {INFO_INIT};
    int fd = 2;

    /* Adjust file descriptor using inline assembly */
    asm ("mov %1, %0\n\t"
         "add $3, %0"
         : "=r" (fd)
         : "r" (fd));

    /* Check if a script file is provided as a command-line argument */
    if (ac == 2)
    {
        fd = open(av[1], O_RDONLY);
        if (fd == -1)
        {
            /* Handle file opening errors */
            if (errno == EACCES)
                exit(126);
            if (errno == ENOENT)
            {
                puts(av[0]);
                puts(": 0: Can't open ");
                puts(av[1]);
                putchar('\n');
                putchar(BUF_FLUSH);
                exit(127);
            }
            return (EXIT_FAILURE);
        }
        info->readfd = fd;
    }

    /* Cleanup and exit */
    return (EXIT_SUCCESS);
}

