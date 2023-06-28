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
	int child_status = 0;
	pid_t child_process;

	child_process = fork();

	if (child_process == -1)
	{
		perror("Error");
		return (1);
	}
	if (child_process == 0)
	{
		if (execve(token, args, __environ) == -1)
		{
			perror("execve");
			return (1);
		}
	}
	else
	{
		wait(&child_status);

		if (WIFEXITED(child_status))
			child_status = WEXITSTATUS(child_status);
		if (!isatty(STDIN_FILENO))
			return (child_status);
	}

	return (0);
}
