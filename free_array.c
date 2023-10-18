#include "shell.h"

/**
 * _realloc - function that reallocates a memory block using malloc and free
 *
 * @potr: a pointer to the memory previously allocated with a call
 * to malloc: malloc(old_size)
 * @old_size: is the size, in bytes, of the allocated space for potr
 * @new_size:  is the new size, in bytes of the new memory block
 *
 * Return: a pointer allocated with the new size
 */

void *_realloc(void *potr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!potr)
		return (malloc(new_size));
	if (!new_size)
		return (free(potr), NULL);
	if (new_size == old_size)
		return (potr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = (old_size < new_size) ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)potr)[old_size];
	free(potr);
	return (p);
}

/**
 * free_array - Entry point
 *
 * @arr: pointer to array of strings
 *
 * Return: Always 0 (Success)
*/
void free_array(char **arr)
{
	int i = 0;

	if (!arr)
		return;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
