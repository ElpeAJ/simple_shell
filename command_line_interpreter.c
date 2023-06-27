#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - function
 *
 * Return: 0
 *
 */

int main(void)
{
	char *args[] = {NULL, NULL};
	char *command = NULL;
	size_t length = 0;
	ssize_t r = 0;
	pid_t child_process;
	char *token;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		fflush(stdout);

		r = getline(&command, &length, stdin);

		token = strtok(command, " \n");
		args[0] = token;

		if (r == -1)
		{
			exit(0);
		}

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
			wait (NULL);
		}
		
		command = NULL;

		token = NULL;
	}

	return (0);
}
