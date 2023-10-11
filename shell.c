#include "shell.h"

int main(int argc, char **argv)
{
    if (argc>1)
        is_file(argv[1]);
    else if (argc == 1 && isatty(STDIN_FILENO))
        is_interactive();
    else
        is_non_interactive()
    return 0;
}