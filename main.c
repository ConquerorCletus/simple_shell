#include "main.h"
/**
 * main - A simple shell program
 * @ac: arument count
 * @argv: pointer to argument vector
 * Return: 0
 */
int main(int ac, char **argv)
{
	char *displayptr = "~simpleShell$ ", *lineptr;
	size_t bytes = 0;

	(void)ac;
	(void)argv;



	printf("%s", displayptr);
	getline(&lineptr, &bytes, stdin);
	printf("%s\n", lineptr);

	free(lineptr);












	return (0);
}
