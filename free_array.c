#include "shell.h"

/**
 * free_array - Entry point
 *
 * @arr: pointer to array of strings
 *
 * Return: Always 0 (Success)
*/
void free_array(char ***arr)
{
	int i = 0;

	if (!(*arr))
		return;
	while ((*arr)[i])
		free((*arr)[i++]);
	free((*arr));
}
