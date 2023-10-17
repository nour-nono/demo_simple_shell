#include "shell.h"

int main(int argc, char **argv)
{
	if (argc > 1)
		is_file(argv[0], argv[1]);
	else if (argc == 1 && isatty(STDIN_FILENO))
		is_interactive(argv[0]);
	else
		is_non_interactive(argv[0]);
	return (0);
}

