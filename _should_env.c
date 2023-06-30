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

	if (command[0] == 'e' && command[1] == 'n' &&
			command[2] == 'v')
	{
		while (environ[i] != NULL)
		{
			printf("current environment: %s\n", environ[i]);
			i++;
		}
	}
}
