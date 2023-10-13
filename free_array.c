#include "shell.h"

void free_array(char ***arr)
{
    int i = 0;

    if (!(*arr))
        return ;
    while ((*arr)[i])
        free((*arr)[i++]);
    free((*arr));
}