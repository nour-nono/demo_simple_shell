#include "shell.h"

char *_getenv(const char *name)
{
    int flag = 0, i = 0;

    while (environ[i])
    {
        if(_strcmp(name ,environ[i]))
            return (environ[i]);
        ++i;
    }
    if(environ[i])return (environ[i]);else return (NULL);
}

