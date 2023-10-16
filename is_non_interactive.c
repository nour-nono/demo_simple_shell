#include "shell.h"

/**
 *  is_non_interactive - Entry point
 *
 * Description: this program prints "_putchar"
 *
 * Return: Always 0 (Success)
*/
void is_non_interactive(void)
{
	char *buff = NULL, *command = NULL, **arr = NULL;
	size_t sz = 0;

	while (getline(&buff, &sz, stdin) != -1)
	{
		remove_comment(buff);
		arr = make_arr_of_str(buff, " \n\t");
		free(buff);
		if (arr[0] && access(arr[0], F_OK | X_OK) == 0)
			exec_command(arr[0], arr);
		else
		{
			command = search_for_command_in_paths(arr[0]);
			if (!command)
				perror("");
			else
				exec_command(command, arr);
		}
		free_array(&arr);
		free(command);
	}
}

