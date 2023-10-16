#include "shell.h"

/**
 * print_env - print environment
 *
 * Description: function that print the environment
 *
 * Return: nothing
 */
void print_env(void)
{
	int i = 0;
	char c = '\n';

	while (*(environ + i) != NULL)
	{
		write(1, *(environ + i), strlen(*(environ + i)));
		write(1, &c, 1);
		i++;
	}
}
/**
 * is_exit - out if is exit
 *
 * @arr: is a pointer
 *
 * Description: this program prints "_putchar"
 *
 * Return: nothing
 */

void is_exit(char **arr)
{
	int i = 0;

	i = _atoi(arr[1]);
	free_array(arr);
	exit(i);
}
