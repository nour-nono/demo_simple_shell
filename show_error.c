#include "shell.h"

/**
 * _pow - function that print integer if %d or %i found
 *
 * @a: the number to be printed
 * @b: int
 * Return: int
 */
int _pow(int a, int b)
{
	int c = a;

	if (b == 0)
	{
		a = 1;
		return (a);
	}
	while (--b)
		a *= c;
	return (a);
}

/**
 * printInteger - function that print integer if %d or %i found
 *
 * @argu : the number to be printed
 *
 * Return: Nothing
 */
void int_to_string(char arr[], int zz)
{
	int num = zz, x, i = 0, a = 0, is_negative = 0, j = 0;
	char c;

	x = num;
	while (x >= 10)
		x /= 10, i++;
	while (i >= 0)
	{
		a = num / _pow(10, i);
		if (i == 0 && is_negative == 1)
			c = (a % 10) + '1';
		else
			c = (a % 10) + '0';
		arr[j] = c;
		i--,++j;
	}
	arr[j] = '\0';
}

/**
 * show_error - function that print integer if %d or %i found
 *
 * @program_name : the number to be printed
 * @buff : the number to be printed
 * Return: Nothing
 */
void show_error(char *program_name,int i,char *buff)
{
	char *out_put = NULL, arr[11], *token = _strtok(buff, "\n");
	int size = _strlen(program_name) + _strlen(buff) + 17;

	int_to_string(arr,i);
	size += _strlen(arr);
	out_put = (char *)malloc(sizeof(char) * size);
	out_put = _strcpy(out_put, program_name);
	out_put = _strcat(out_put, ": ");
	out_put = _strcat(out_put, arr);
	out_put = _strcat(out_put, ": ");
	out_put = _strcat(out_put, token);
	out_put = _strcat(out_put, ": ");
	out_put = _strcat(out_put, "not found\n");
	write(2, out_put, size);
	free(out_put);
}