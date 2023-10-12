#include "shell.h"

char *search_for_command_in_paths(char *command)
{
    char *path_copy = _get_env("PATH");
    char all_paths = make_arr_of_str(path_copy, ":");
    char search_in_this_path;
    int i = 0;

    while (all_paths[i])
    {
        search_in_this_path = _strdup(all_paths[i]);
        _strcat(search_in_this_path, "/");
        _strcat(search_in_this_path, command);
        if (access(search_in_this_path, X_OK) == 0)
            break;
        ++i;
    }
    i = 0;
    free_array(&all_paths);
    if (access(search_in_this_path, X_OK) == 0)
        return (search_in_this_path);
    else
        return (NULL);
}

void exec_command(char **command_and_argu)
{
    pid_t child_id = fork();

    if (child_id == 0)
    {
        execve(command_and_argu[0], command_and_argu, NULL);
    }
    else if (child_id > 0)
    {
        wait(NULL);
    }
}