#include "Builtin1.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * main - The main entry point
 * @argc: The argument count
 * @argv: The argument vector
 * Return: Returns 0 on success
 */
int main(int argc, char *argv[])
{
    char *shell_path = "/bin/sh"; /* Absolute path */
    pid_t child_pid;
    int status;
    char *current_file = argv[0];
    char **env_var = environ;
    char *shell_cmds[3];

    shell_cmds[0] = current_file;
    shell_cmds[1] = "-s";
    shell_cmds[2] = NULL;

    if (argc == 0)
    {
        exit(0);
    }

    child_pid = fork();

    if (child_pid == 0)
    {
        execve(shell_path, shell_cmds, env_var);
    }
    else
    {
        wait(&status);
    }

    return 0;
}

