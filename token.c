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

    if (!str)
        str = last_of_string;
    if (!str)
        return (NULL);
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
char **make_arr_of_str(char *str, char *delimiters)
{
    int i = 0;
    char *token;
    char **arr_of_str = malloc(2024);

    token = _strtok(str, delimiters);
    while (token != NULL)
    {
        arr_of_str[i] = token;
        token = _strtok(NULL, delimiters);
            i++;
    }
    arr_of_str[i] = NULL;
    return (arr_of_str);
}