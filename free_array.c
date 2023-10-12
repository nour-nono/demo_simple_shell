#include "shell.h"

void free_array(char ***arr)
{
    while (*arr[i])
        free(*arr[i++]);
    free(*arr);
}