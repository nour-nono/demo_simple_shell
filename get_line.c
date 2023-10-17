#include "shell.h"

/**
 * get_line - copy string in heap
 *
 * @lineptr: string
 * @n: string
 * @fd: string
 * @flag1: string
 *
 * Return: string.
 */
ssize_t get_line(char **lineptr, size_t *n, int fd, int flag1)
{
	static char buffer[8192];
	static int sz = 0, i = 0, flag = 1;
	size_t j = 0;

	if (flag1)
		i = 0;
	if (flag1 || flag)
		sz = read(fd, buffer, 8180), flag = 0;
	if (sz == -1)
	{
		perror("");
		return (-1);
	}
	else if (sz > 0)
		buffer[sz] = '\0';
	if (buffer[i] == '\0')
		return (-1);
	if (!(*lineptr))
		(*lineptr) = malloc(sizeof(char) * 1000);
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		(*lineptr)[j++] = buffer[i++];
	}
	while (buffer[i] == '\n' || buffer[i] == ' ' || buffer[i] == '\t')
		++i;
	(*lineptr) = realloc((*lineptr), j + 1);
	(*lineptr)[j] = '\0';
	if (buffer[i] == '\0')
		--j;
	*n = j;
	return (*n);
}
