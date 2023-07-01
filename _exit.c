#include "main.h"

/**
 * _should_exit - function that checks whether to close the shell
 * @command: user prompt
 * @status_code: the status code
 *
 * return: Nothing
 */

void _should_exit(char *command, int status_code, char **args)
{
	int i = 0;

	if (command[0] == 'e' && command[1] == 'x' &&
		command[2] == 'i' && command[3] == 't')
	{
		free(command);
		if (args != NULL && args[1] != NULL)
		{
			status_code = atoi(args[1]);
			for (i = 0; args[i] != NULL; i++)
				free(args[i]);
			free(args);
		}
		free(args[0]);
		free(args);
		exit(status_code);
	}
}
