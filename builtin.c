#include "main.h"

/**
  * _cd - This function changes the directory.
  * @args: argument.
  * @input: Input.
  * Return: 1.
  */
int _cd(char **args, __attribute__((unused)) char *input)
{
	char *new_dir;
	int i;

	if (args[1] == NULL)
	{
		new_dir = _getenv("HOME");
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		new_dir = _getenv("OLDPWD");
		for (i = 0; new_dir[i]; i++)
			_putchar(new_dir[i]);
		_putchar('\n');
	}
	else
	{
		new_dir = args[1];
	}

	if (chdir(new_dir) == -1)
	{
		perror("hsh");
	}
	else
	{
		_setenv("OLDPWD", _getenv("PWD"), 1);
		_setenv("PWD", getcwd(NULL, 0), 1);
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
	int status;

	if (args[1] == NULL)
		return (0);

	status = _atoi(args[1]);

	if (status < 0)
	{
		perror("hsh:");
		return (1);
	}
	else if (status == 0)
	{
		return (0);
	}
	else if (status >= 256)
	{
		free(input);
		free(args);
		exit(status - 256);
	}
	else
	{
		free(input);
		free(args);
		exit(status);
	}
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
 * _setenv - Changes or adds an environment variable.
 * @name: Name of the environment variable.
 * @value: Value of the environment variable.
 * @overwrite: If variable already exists, overwrite it or not.
 *
 * Return: 1 on success, -1 on failure.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char *tmp, new_variable[1024], **ep = environ;
	char **ev;
	int i, count = 0;

	if (!name || !value)
		return (-1);

	tmp = _getenv(name);
	if (tmp != NULL)
	{
		if (!overwrite)
			return (0);

		else
			_strcpy(tmp, value);
	}
	else
	{
		while (ep[count])
			count++;
		ev = malloc((count + 2) * sizeof(char *));
		if (!ev)
			return (-1);
		for (i = 0; ep[i]; i++)
			ev[i] = ep[i];
		_strcat(new_variable, name);
		_strcat(new_variable, "=");
		_strcat(new_variable, value);
		ev[i++] = new_variable;
		ev[i] = NULL;
		environ = ev;
		free(ep);
	}
	return (1);
}

