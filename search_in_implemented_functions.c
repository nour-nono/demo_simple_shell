#include "shell.h"

int search_in_implemented_functions(char **arr, int *status,int i,char *program_name)
{
    int flag = 1;

    if (_strcmp(arr[0],"exit") == 1)
    {
        is_exit(arr, *status, i, program_name); 
        flag = 0;
    }
    else if (_strcmp(arr[0],"env") == 1)
    {
        print_env();
        flag = 0;
    }
    else if (_strcmp(arr[0],"setenv") == 1)
    {
        if(arr[1] == NULL)
            perror("there is no key or there is no value");
        else if(arr[2] == NULL)
            perror("there is no key or there is no value");
        flag = 0;
    }
    else if (_strcmp(arr[0],"unsetenv") == 1)
    {
        if(arr[1] == NULL)
            perror("there is no key");
        flag = 0;
    }
    else if (_strcmp(arr[0],"cd") == 1)
    {
        flag = 0;
    }
    return (flag);
}