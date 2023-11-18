#include "shell.h"
#include "Prints.h"

/**
 * is_exec_cd - Determines if a file is an executable command
 * @info_data: Pointer to the info struct
 * @path: Path to the file
 *
 * Return: 1 if true, and 0 otherwise
 */
int is_exec_cd(info_t *info_data, char *path)
{
    struct stat file_stats;

    (void)info_data;
    if (!path || stat(path, &file_stats))
        return (0);

    if (file_stats.st_mode & S_IFREG)
    {
        return (1);
    }
    return (0);
}

/**
 * duplicate_ch - Duplicates characters
 * @paths: Denotes the PATH string
 * @start: Denotes the starting index
 * @end: Denotes the stopping index
 *
 * Return: Returns a pointer to a new buffer
 */
char *duplicate_ch(char *paths, int start, int end)
{
    static char buffer[1024];
    int bufferx= 0, path= 0;

    for (bufferx= 0, path = start; path < end; path++)
        if (paths[path] != ':')
            buffer[bufferx++] = paths[path];
    buffer[bufferx] = 0;
    return (buffer);
}

/**
 * find_path - Finds the command in the PATH string
 * @info_data: Pointer to the info struct
 * @path_str: Denotes the PATH string
 * @command: Denotes the command to find
 *
 * Return: Returns the full path of the command if found, or NULL
 */
char *find_path(info_t *info_data, char *path_str, char *command)
{
    int path_index = 0, current_position = 0;
    char *full_path;

    if (!path_str)
        return (NULL);
    if ((custom_strlen(command) > 2) && string_starts_with(command, "./"))
    {
        if (is_exec_cd(info_data, command))
            return (command);
    }
    while (1)
    {
        if (!path_str[path_index] || path_str[path_index] == ':')
        {
            full_path = duplicate_ch(path_str, current_position, path_index);
            if (!*full_path)
                custom_strcat(full_path, command);
            else
            {
                custom_strcat(full_path, "/");
                custom_strcat(full_path, command);
            }
            if (is_exec_cd(info_data, full_path))
                return (full_path);
            if (!path_str[path_index])
                break;
            current_position = path_index;
        }
        path_index++;
    }
    return (NULL);
}

