#include "shell.h"

int search_for_env(const char *name)
{
    int i = 0;

    while (environ[i])
    {
        char *env_copy = strdup(environ[i]);
        char *token = _strtok(env_copy, "=");
        if (_strcmp(token, name))
        {
            free(env_copy);
            return (i);
        }
        ++i;
    }
    return (i);
}
char *_get_env(const char *name)
{
    int env_indx = search_for_env(name);
    char *env_copy, *env_val;
    if (!environ[env_indx])
        return (NULL);
    *env_copy = strdup(environ[env_indx]);
    _strtok(env_copy, "=");
    *env_val = _strtok(NULL, "=");
    return (env_val);
}
int _set_env(char *key, char *value, int overwrite)
{
    char *new_env;
    int env_indx = search_for_env(key);

    if (environ[env_indx])
    {
        if (overwrite)
        {
            new_env = malloc(_strlen(key) + _strlen(value) + 2);
            _strcpy(new_env, key), _strcat(new_env, "="), _strcat(new_env, value);
            environ[env_indx] = new_env;
        }
    }
    else
    {
        new_env = malloc(_strlen(key) + _strlen(value) + 2);
        _strcpy(new_env, key), _strcat(new_env, "="), _strcat(new_env, value);
        environ[env_indx] = new_env;
    }
    return (0);
}
int _unset_env(char *key)
{
    int env_indx = search_for_env(key);
    if (environ[env_indx])
    {
        _strtok(environ[env_indx], "=");
        return (0);
    }
    else
        return (-1);
}