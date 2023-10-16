#include "shell.h"

/**
 *  is_interactive - Entry point
 *
 * Description: this program prints "_putchar"
 *
 * Return: Always 0 (Success)
*/
void is_interactive(void)
{
	char *prompt = "($) ";

	while (1)
	{
		char *buff = NULL, *command = NULL, **arr = NULL;
		ssize_t sz = 0, i = 0;

		write(1, prompt, 4);
		if (getline(&buff, &sz, stdin) == -1)
			free(buff), exit(0);
		arr = make_arr_of_str(buff, " \n\t");
		free(buff);
		if (arr[0] && access(arr[0], F_OK | X_OK) == 0)
			exec_command(arr[0], arr);
		else
		{
			command = search_for_command_in_paths(arr[0]);
			if (!command)
				printf("command not found\n");
			else
				exec_command(command, arr);
		}
		free(command);
		free_array(&arr);
	}
}
