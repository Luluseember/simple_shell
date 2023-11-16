#include "shell.h"
#define MAX_CMD_LEN 100

/**
 * run_command - fork a new process
 * @cmd: command to be executed
 * Return: 0
 */
int run_command(char *cmd)
{
    char *arguments[] = {NULL};
    /* Fork a new process */
    pid_t process_id = fork();

    if (process_id < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (process_id == 0)
    {
        /* Child process */
        pid_t child_pid = getpid();
        pid_t parent_pid = getppid();

        printf("Child PID: %d\n", child_pid);
        printf("Parent PID: %d\n", parent_pid);
        /* create token and concatenate the PATH */
        /*handle_path(char *PATH);*/
        /* Handle arguments */
        execve(cmd, arguments, NULL);
        perror("exec");
        exit(EXIT_FAILURE);
    }
    else
    {
        /* Parent process */
        int status;

        wait(&status);
        printf("Child process exited with status: %d\n", WEXITSTATUS(status));
    }
    return 0;
}

