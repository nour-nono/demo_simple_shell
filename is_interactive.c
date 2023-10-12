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
        char **arr = make_arr_of_str(buff, " ");
        if (access(arr[0], X_OK) == 0)
            exec_command(arr);
        else
            command = search_for_command_in_paths(arr[0]);
        if (command)
            printf("command not found\n");
        else
            exec_command(arr);
        free_array(&arr);
        free(buff);
        // printf("\n");
    }
}
