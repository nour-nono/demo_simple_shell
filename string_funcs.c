#include "shell.h"

/**
 *  _strlen - Entry point
 *
 * @s: is a pointer
 *
 * Description: this program prints "_putchar"
 *
 * Return: Always 0 (Success)
*/
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);
	while (s[i] != '\0')
		++i;
	return (i);
}
/**
 * _strcpy - Entry point
 *
 * @dest: is a pointer to arr of int
 *
 * @src: nums
 *
 * Description: this program prints "_putchar"
 *
 * Return: Always 0 (Success)
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;
	int j = 0;

    if (!src || !dest)
        return (NULL);
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		++i;
		++j;
	}
	dest[i] = src[j];
	return (dest);
}
/**
 * _strncpy - Entry point
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
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

    if (!src || !dest)
        return (NULL);
	while (src[j] != '\0' && n)
	{
		dest[i] = src[j];
		++i;
		++j;
		--n;
	}
	while (n > 0)
	{
		dest[i] = '\0';
		--n;
		++i;
	}
	return (dest);
}
/**
 * _strcat - Entry point
 *
 * @dest: is a pointer to arr of int
 *
 * @src: nums
 *
 * Description: this program prints "_putchar"
 *
 * Return: Always 0 (Success)
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

    if (!dest)
        return (src);
    if (!src)
        return (dest);
	while (dest[i] != '\0')
		++i;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		++i;
		++j;
	}
	dest[i] = src[j];
	return (dest);
}
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