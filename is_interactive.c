#include "shell.h"

/**
 *  is_interactive - Entry point
 *
 * Description: this program prints "_putchar"
 *
 * Return: Always 0 (Success)
*/
void is_interactive(char *program_name)
{
	char *prompt = "$ ";
	int i = 1;

	while (1)
	{
		char *buff = NULL, *command = NULL, **arr = NULL;
		size_t sz = 0;

		write(1, prompt, 2);
		if (get_line(&buff, &sz, STDIN_FILENO, 1) == -1)
			free(buff), exit(0);
		remove_comment(buff);
		arr = make_arr_of_str(buff, " \n\t");
		if (arr[0] && access(arr[0], F_OK | X_OK) == 0)
			exec_command(arr[0], arr);
		else
		{
			command = search_for_command_in_paths(arr[0]);
			if (!command)
				show_error(program_name, i, buff, "not found\n");
			else
				exec_command(command, arr);
		}
		free(buff);
		free(command);
		free_array(arr);
		++i;
	}
}
