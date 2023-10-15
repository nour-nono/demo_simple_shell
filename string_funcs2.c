#include "shell.h"

/**
 * _strncat - Entry point
 *
 * @dest: is a pointer to arr of int
 *
 * @src: nums
 *
 * @n: a num
 *
 * Description: this program prints "_putchar"
 *
 * Return: Always 0 (Success)
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

    if (!dest)
        return (NULL);
    if (!src)
        return (dest);
	while (dest[i] != '\0')
		++i;
	while (src[j] != '\0' && n--)
	{
		dest[i] = src[j];
		++i;
		++j;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcmp - Entry point
 *
 * @s1: is a pointer to arr of int
 *
 * @s2: nums
 *
 * Description: this program prints "_putchar"
 *
 * Return: Always 0 (Success)
 */
int _strcmp(const char *s1,const char *s2)
{
    int ans = 1, i = 0;

    if (!s1 || !s2)
        return (0);
    while (s1[i])
    {
        if (s1[i] != s2[i])
        {
            ans = 0;
            break;
        }
        ++i;
    }
	return (ans);
}
/**
 * _strdup - copy string in heap
 * @str: string
 *
 * Return: string.
 */

char *_strdup(char *str)
{
	unsigned int i = 0, j = 0;
	char *ch;

	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
		++i;
	ch = (char *) malloc((i + 1) * sizeof(char));
	if (ch == NULL)
		return (NULL);
	while (j <= i)
	{
		ch[j] = str[j];
		++j;
	}
	return (ch);
}