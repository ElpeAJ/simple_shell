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
	char *args[] = {NULL};
	char *command = NULL;
	size_t length = 0;
	ssize_t r = 0;
	char *const env[] = {NULL};

	while (1)
	{
		printf("$");
		fflush(stdout);

		r = getline(&command, &length, stdin);

		if (r == -1)
		{
			perror("Error");
			return (1);
		}
		else if (r == 0)
		{
			if (execve(command, args, env) == -1)
			{
			perror("execve");
			return (1);
			}
		}
		else
		{
			wait (NULL);
		}
		free(command);
	}

	return (0);
}
