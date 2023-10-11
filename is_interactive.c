#include "shell.h"

void is_interactive()
{
    char *prompt = "($) ";
    while (1)
    {
        printf("%s",prompt);
        getline(&s, &z, stdin);
        printf("%s", s);
    }
