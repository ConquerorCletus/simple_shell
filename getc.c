#include "main.h"

/**
 * _getc - Reads text file and prints to the POSIX
 * Return: char
 */

int _getc(void)
{
	char buf[1], *ptr;
	int reader;

	reader = read(STDIN_FILENO, buf, 1);
	if (reader > 0)
	{
		ptr = buf;
		return (*ptr);
	}

	if (reader == -1)
		return (0);

	return (EOF);
}

/**
  * _splitters - Split line in console.
  * @line: Line retrieved from user input.
  * Return: Array
  */
char **_splitters(char *line)
{
	int buffs = 64, position = 0;
	char **tokens, *token;

	tokens = malloc(buffs * sizeof(char *));
	if (!tokens)
	{
		perror("hsh: allocation error\n");
		return (NULL);
	}
	token = _strtok(line, " \t\r\n\a");
	for (; token != NULL; token = _strtok(NULL, " \t\r\n\a"))
	{
		tokens[position] = token;
		position++;

		if (position >= buffs)
		{
			buffs += 64;
			tokens = _realloc(tokens, buffs - 64, buffs * sizeof(char *));
			if (!tokens)
			{
				perror("hsh: allocation error\n");
				return (NULL);
			}
		}
	}
	tokens[position] = NULL;
	return (tokens);
}
