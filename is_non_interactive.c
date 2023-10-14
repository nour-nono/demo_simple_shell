#include "shell.h"

void is_non_interactive()
{
        char *buff = NULL, *command = NULL;
        ssize_t sz = 0, i = 0;
        while (getline(&buff, &sz, stdin) != -1)
        {
        char **arr = make_arr_of_str(buff, " \n\t");
        
        if (arr[0] && access(arr[0], F_OK|X_OK) == 0)
            exec_command(arr[0],arr);
        else
        {
            command = search_for_command_in_paths(arr[0]);
            _strcpy(arr[0],command);
        if (!command)
            perror("");
        else
            exec_command(command,arr);
        }
        free_array(&arr);
        free(command);
        }
        free(buff);
}