#include "shell.h"

/**
 * search_for_env - copy string in heap
 * @name: string
 *
 * Return: string.
 */
int search_for_env(const char *name)
{
	int i = 0;
	char *env_copy = NULL, *token = NULL;

	while (environ[i])
	{
		env_copy = strdup(environ[i]), token = _strtok(env_copy, "=");
		if (_strcmp(token, name))
		{
			free(env_copy);
			return (i);
		}
		free(env_copy);
		++i;
	}
	return (i);
}

/**
 * _get_env - copy string in heap
 * @name: string
 *
 * Return: string.
 */
char *_get_env(const char *name)
{
	int env_indx = search_for_env(name);
	char *env_copy = NULL, *env_val = NULL;

	if (!environ[env_indx])
		return (NULL);
	env_copy = strdup(environ[env_indx]);
	_strtok(env_copy, "=");
	env_val = _strdup(_strtok(NULL, "="));
	free(env_copy);
	return (env_val);
}

/**
 * _set_env - copy string in heap
 * @key: string
 * @value: string
 * @overwrite: string
 *
 * Return: string.
 */
int _set_env(char *key, char *value, int overwrite)
{
	char *new_env = NULL;
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

/**
 * _unset_env - copy string in heap
 * @key: string
 *
 * Return: string.
 */
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
