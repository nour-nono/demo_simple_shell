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
	int i = 1;
	char *buff = NULL, *command = NULL, **arr = NULL;
	size_t sz = 0;

	while (get_line(&buff, &sz, STDIN_FILENO, 0) != -1)
	{
		remove_comment(buff);
		arr = make_arr_of_str(buff, " \n\t");
		if (arr[0] && access(arr[0], F_OK | X_OK) == 0)
			exec_command(arr[0], arr);
		else
		{
			command = search_for_command_in_paths(arr[0]);
			if (!command)
				show_error(program_name, i, buff);
			else
				exec_command(command, arr);
		}
		free(buff);
		free_array(arr);
		free(command);
		++i;
		buff = NULL, command = NULL, arr = NULL, sz = 0;
	}
}

