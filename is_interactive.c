#include "shell.h"

void is_interactive()
{
    char *prompt = "($) ";
    while (1)
    {
        char *buff = NULL, *command = NULL;
        ssize_t sz = 0, i = 0;
        printf("%s", prompt);
        if (getline(&buff, &sz, stdin) == -1)
            free(buff), exit(0);
        char **arr = make_arr_of_str(buff, " \n\t");
        if (access(arr[0], X_OK) == 0)
            exec_command(arr);
        else
        {
            command = search_for_command_in_paths(arr[0]);
            _strcpy(arr[0], command);
            if (!command)
                printf("command not found\n");
            else
                exec_command(arr);
        }
        free(command);
        free_array(&arr);
        free(buff);
    }
}
