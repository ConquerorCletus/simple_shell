#include "main.h"
/**
 * _getenv - This function gets an environment variable.
 * @name: Name of the environment variable to lookup.
 * Return: The variable value.
 */

char *_getenv(const char *name)
{
	size_t len;
	char **value;

	if (name == NULL)
		return (NULL);

	len = _strlen((char *)name);


	if (environ == NULL)
		return (NULL);
	len--;
	value = environ;
	while (*value != NULL)
	{
		if (!_strncmp(*value, name, len) && (*value)[len + 1] == '=')
			return (&(*value)[len + 2]);
		value++;
	}
	return (NULL);
}
