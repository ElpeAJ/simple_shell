#include "main.h"

/**
 * _should_exit - function that checks whether to close the shell
 * @command: user prompt
 * @status_code: the status code
 *
 * return: Nothing
 */

void _should_exit(char *command, int status_code)
{
	if (command[0] == 'e' && command[1] == 'x' &&
		command[2] == 'i' && command[3] == 't')
	{
		free(command);
		exit(status_code);
	}
}
