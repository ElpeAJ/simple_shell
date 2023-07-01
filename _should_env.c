#include "main.h"

/**
 * _should_env - function that prints the current environment
 * @command: user prompt
 *
 * Return: nothing
 */

void _should_env(char *command)
{
	int i = 0;

	if ((strcmp(command, "env") == 0) && environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
