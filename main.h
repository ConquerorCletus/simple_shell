#ifndef _MAIN_H_
#define _MAIN_H_

/* Required libraries */
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
/* Environmental variables */
extern char **environ;

void prompt(void);
char *_read_line(void);
char **_splitters(char *line);
int _execute(char **args, char *input);
int initialize(char **args);
void sigint_handler(int sig);

int hsh_exit(char **args, char *input);
int _cd(char **args, __attribute__((unused)) char *input);
/**
 * _help - Displays help.
 * @args: argument passed.
 * @input: Input command.
 * Return:1
 */
int _help(__attribute__((unused)) char **args,
		__attribute__((unused)) char *input);

/**
 * _env - Displays working Environment.
 * @args:arguments passed
 * @input: input command
 * Return:1
 */
int _env(__attribute__((unused)) char **args,
	__attribute__((unused)) char *input);
int _setenv(char *name, char *value);

ssize_t get_line(char **b, size_t *bufsize, FILE *stream);
int _getc(void);

char *_strtok(char *s, const char *delim);
char *_strtok_r(char *s, const char *delim, char **save_str);
int _strcspn(char *s, const char *delim);
int _strspn(char *s, const char *delim);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

char *_getenv(const char *name);
char **_path(char *path);
char **_split_path(char *line, char *copy_line);
char **_check_path(char **args, int *flag);

int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
int _putchar(char c);
void _puts(char *str);
int _atoi(char *s);
B

#endif
