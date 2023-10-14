#include "shell.h"

/**
 * search_for_command_in_paths - copy string in heap
 * @command: string
 *
 * Return: string.
 */
char *search_for_command_in_paths(char *command)
{
    char *path_copy = _get_env("PATH");
    char **all_paths = make_arr_of_str(path_copy, ":\n\t");
    char *search_in_this_path = NULL;
    free(path_copy);
    int i = 0;

    while (all_paths[i])
    {
        search_in_this_path = malloc(_strlen(all_paths[i])+_strlen(command)+2);
        _strcpy(search_in_this_path,all_paths[i]);
        _strcat(search_in_this_path, "/");
        _strcat(search_in_this_path, command);
        if (search_in_this_path && access(search_in_this_path, F_OK|X_OK) == 0)
            break;
        free(search_in_this_path);
        ++i;
    }
    i = 0;
    free_array(&all_paths);
    if (search_in_this_path && access(search_in_this_path, F_OK|X_OK) == 0)
        return (search_in_this_path);
    else
        return (NULL);
}

void exec_command(char *command, char **command_and_argu)
{
    pid_t child_id = fork();

    if (child_id == 0)
    {
        execve(command, command_and_argu, NULL);
    }
    else if (child_id > 0)
    {
        wait(NULL);
    }
}