#include "shell.h"

void is_interactive()
{
    char *prompt = "($) ";
    while (1)
    {
        char *buff = NULL;
        ssize_t sz = 0;
        printf("%s", prompt);
        getline(&buff, &sz, stdin);
        char **arr = **make_arr_of_str(buff, " ")
        printf("%s", buff);
        free(buff)
    }
}

