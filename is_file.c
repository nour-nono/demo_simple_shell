#include "shell.h"

/**
 * is_file - Entry point
 *
 * Description: this program prints "_putchar"
 *
 * Return: Always 0 (Success)
*/
void is_file(char *filename)
{
    int fd = open(filename, O_RDONLY);
    //getline()
}
