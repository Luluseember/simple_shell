#include "shell.h"
#include "Prints.h"
#define MAX_CMD_LEN 100

/**
 * display_prompt - Display a prompt and wait for the user to type a command
 * Return: Nothing, as it is void
 */
int display_prompt(void)
{
    char user_comd[MAX_CMD_LEN];
    /*char *path = getenv("PATH");*/
    /*char *args[MAX_CMD_LEN];*/

    while (true)
    {
        if (isatty(STDIN_FILENO))
            printf("custom_shell >");

        fflush(stdout);

        if (fgets(user_comd, MAX_CMD_LEN, stdin) == NULL)
        {
            break;
        }

        user_comd[strcspn(user_comd, "\n")] = '\0';
    }

    return 0;
}

