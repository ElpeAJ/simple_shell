#include "main.h"

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
			exit(0);

		_fork(token, args);

		command = NULL;
		token = NULL;
	}

	return (0);
}
