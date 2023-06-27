#include "main.h"

/**
 * _fork - function that ...
 * @token: ...
 * @args: ...
 * Return: 0
 *
 */

int _fork(char *token, char **args)
{
	pid_t child_process;

	child_process = fork();

	if (child_process == -1)
	{
		perror("Error");
		return (1);
	}
	else if (child_process == 0)
	{
		if (execve(token, args, __environ) == -1)
		{
			perror("execve");
			return (1);
		}
	}
	else
	{
		wait(NULL);
	}

	return (0);
}
