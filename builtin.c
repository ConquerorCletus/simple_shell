#include "main.h"

/**
  * _cd - This function changes the directory.
  * @args: argument.
  * @input: Input.
  * Return: 1.
  */
int _cd(char **args, __attribute__((unused)) char *input)
{

	if (args[1] == NULL)
	{
		if (chdir(_getenv("HOME")) != 0)
		{
			perror("hsh:");
		}
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh:");
		}
	}
	return (1);
}


/**
  * _help - Display the help about a command.
  * @args: arguments passed..
  * @input: Input.
  * Return: 1
  */
int _help(__attribute__((unused)) char **args,
		__attribute__((unused)) char *input)
{
	int i;
	char *builtin_str[] = {"cd", "help", "exit"};

	for (i = 0; i < 3; i++)
	{
		write(STDOUT_FILENO, builtin_str[i], _strlen(builtin_str[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}

/**
  * hsh_exit - Exit to the shell.
  * @args: List of arguments passed from parsing.
  * @input: Input line for free.
  * Return: 0 if works.
  */
int hsh_exit(__attribute__((unused)) char **args, char *input)
{
	/*
	 * Simple shell 0.3 +
	 *
	 * Implement the exit built-in, that exits the shell
	 * Usage: exit
	 * You don’t have to handle any argument to the built-in exitint var;

	if (args[1] == NULL)
		return (0);

	var = _atoi(args[1]);

	if (var < 0)
	{
		perror("hsh:");
		return (1);
	}
	else if (var == 0)
	{
		return (0);
	}
	else if (var >= 256)
	{
		free(input);
		free(args);
		exit(var - 256);
	}
	else
	{
	*/
		free(input);
		free(args);
		exit(EXIT_SUCCESS);
	/*
	 * }
	 */
}

/**
  * _env - Display the environ in the shell.
  * @args: List of arguments passed from parsing.
  * @input: Input line for free.
  * Return: 1 if works.
  */
int _env(__attribute__((unused)) char **args,
		__attribute__((unused)) char *input)
{
	int i = 0;

	while (environ[i] != 0)
	{

		_puts(environ[i]);
		_puts("\n");
		i++;
	}
	return (1);
}

/**
  * _setenv - Set a environment variable.
  * @name:Name of the variable
  * @value: Value in the variable.
  * Return: 1.
  */
int _setenv(char *name, char *value)
{
	char *tmp, new_variable[1024], **ep = environ;
	char **ev;
	int overwrite = 0, i;


	if (value == NULL)
	{
		perror("hsh:");
	}
	tmp = _getenv(name);
	if (tmp != NULL)
	{
		_strcpy(tmp, value);
	}
	else
	{
		while (ep[overwrite] != NULL)
		{
			overwrite++;
		}
		overwrite += 2;
		ev = malloc(overwrite * sizeof(char *));
		for (i = 0; ep[i] != NULL; i++)
		{
			ev[i] = ep[i];
		}
		_strcat(new_variable, name);
		_strcat(new_variable, "=");
		_strcat(new_variable, value);
		ev[i] = new_variable;
		ev[++i] = NULL;
		environ = ev;
		free(ep);
	}

	return (1);
}
