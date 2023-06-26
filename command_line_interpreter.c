#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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
		r = getline(&command, &length, stdin);
		printf("\n");

		if (r == -1)
		{
			perror("Error");
		}
		else if (r != -1)
		{
			execve(command, args, env);
			perror("execve");
		}
		free(command);
	}

	return (0);
}
