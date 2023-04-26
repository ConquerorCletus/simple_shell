#include "main.h"

/**
 * allocation_err -  Check allocation error
 * @buffer: buffer
 * Return: -1 if error, 0 otherwise
 */
int allocation_err(char *buffer)
{
	if (buffer == false)
	{
		perror("hsh: allocation error\n");
		return (-1);
	}
	else
		return (0);
}

/**
 * get_line - Reads an entire line
 * @lptr: pointer to buffer
 * @n: size of buffer
 * @stream: File
 * Return: Return the number of characters
 */
ssize_t get_line(char **lptr, size_t *n, __attribute__((unused))FILE * stream)
{
	size_t buffsize = 1024, index = 0;
	int c, f = 0;
	char *buffer;

	if (*n == 0)
		buffsize = 1024;
	buffer = malloc(sizeof(char) * (buffsize));
	if (allocation_err(buffer) == -1)
		return (-1);
	*lptr = buffer;
	while (1)
	{fflush(stdout);
		c = _getc();
		if (c == EOF || c == '\n')
		{*(buffer + index) = '\0';
			if (c == EOF)
				return (-1);
			else
				return (index + 1);
		} else if (c == ' ')
		{
			if (f == 0)
			{ f = 1;
				*(buffer + index) = c;
				index++;
			}
		} else
		{
			f = 0;
			*(buffer + index) = c;
			index++;
		}
		if (index >= buffsize)
		{
			buffsize += 1024;
			buffer = _realloc(buffer, buffsize - 1024, buffsize);
			if (allocation_err(buffer) == -1)
				return (-1);
		}
	}
}
