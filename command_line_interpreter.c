#include "main.h"

/**
 * main - function prototype
 * @argc: argument count of passed argument
 * @argv: argument vector
 * Return: 0
 */
int main(__attribute((unused))int argc, __attribute((unused))char **argv)
{
	int status_code;
	char *args[] = {NULL, NULL};
	char *command = NULL;
	size_t length = 0;
	ssize_t r = 0;
	char *token = NULL;
	int command_number = 1;
	struct stat sb;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		fflush(stdout);

		r = getline(&command, &length, stdin);

		if (r == -1)
		{
			free(command);
			printf("\n");
			exit(status_code);
		}
		token = strtok(command, " \n");
		if (token != NULL)
		{
			args[0] = token;
			if (stat(token, &sb) == -1)
				status_code = _perror(argv[0], command_number, token);
			else
				status_code = _fork(token, args);
		}
		command_number++;
	}

	free(command);
	free(token);
	command = NULL;
	token = NULL;
	return (0);
}
