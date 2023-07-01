#include "main.h"

/**
 * _should_env - function that prints the current environment
 * @command: user prompt
 * @args: 2nd parameter
 * Return: 0 if env is command, otherwise 1
 */

int _should_env(char *command, char **args)
{
	int i = 0;

	if (strcmp(command, "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			printf("%s\n", environ[i]);
		}
		for (i = 0; args[i] != NULL; i++)
			free(args[i]);
		free(args);
		return (0);
	}
	return (1);
}
