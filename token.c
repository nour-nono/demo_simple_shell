#include "shell.h"

unsigned int is_delim(char c, char *delimiters)
{
    while (*delimiters != '\0')
    {
        if (c == *delimiters)
            return 1;
        delimiters++;
    }
    return (0);
}

char *_strtok(char *str, char *delimiters)
{
    static char *last_of_string;
    // char *return_of_the_rest;

    if (!str)
    {
        str = last_of_string;
    }
    if (!str)
    {
        return (NULL);
    }
    while (1)
    {
        if (is_delim(*str, delimiters))
        {
            str++;
            continue;
        }
        if (*str == '\0')
        {
            return (NULL);
        }
        break;
    }
    char *return_of_the_rest = str;
    while (1)
    {
        if (*str == '\0')
        {
            last_of_string = str;
            return (return_of_the_rest);
        }
        if (is_delim(*str, delimiters))
        {
            *str = '\0';
            last_of_string = str + 1;
            return (return_of_the_rest);
        }
        str++;
    }
}