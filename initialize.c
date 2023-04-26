#include "main.h"
/**
  * initialize - Function executes arguments.
  * @args: arguments constant.
  * Return: 1
  */
int initialize(char **args)
{
	int status, pid, flag = 0;

	args = _check_path(args, &flag);

	if (args == NULL)
		return (1);

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("hsh");
		}
		if (flag == 1)
			free(args[0]);
		return (-1);
	}
	else if (pid < 0)
	{
		perror("hsh");
		if (flag == 1)
			free(args[0]);
		return (-1);

	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	if (flag == 1)
		free(args[0]);
	return (1);
}
