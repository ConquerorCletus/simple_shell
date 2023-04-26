#include "main.h"

/**
 * prompt - This function reads input, and executes
 * arguments by iterating through the shell
 * program.
 * Return: void
*/

void prompt(void)
{
	char *input, **args;
	int fd_stat, interactive_mode = 1, len;

	if (isatty(STDIN_FILENO) != 1)
		interactive_mode = 0;

	signal(SIGINT, sigint_handler);

	do {
		if (interactive_mode != 0)
		{
			len = _strlen("$ ");
			write(STDOUT_FILENO, "$ ", len);
		}

		input = _read_line();
		if (input == NULL)
			return;

		args = _splitters(input);
		if (args == NULL)
		{
			free(input);
			return;
		}

		fd_stat = _execute(args, input);

		free(input);
		free(args);

	} while (fd_stat == 1);
}
