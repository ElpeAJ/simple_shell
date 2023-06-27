#include "main.h"

/**
 * main - function prototype
 * @argc: argument count of passed argument
 * @argv: argument vector
 * Return: 0
 */
int main(__attribute((unused))int argc, __attribute((unused))char **argv)
{
	int status_code = 0;
	char *args[] = {NULL, NULL};
	char *command = NULL;
	size_t length = 0;
	ssize_t r = 0;
	char *token;
	int command_number = 1;
	struct stat sb;

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
			printf("\n");
			exit(status_code);
		}
		if (token != NULL)
		{
			if (stat(token, &sb) == -1)
				status_code = _perror(argv[0], command_number, token);
			else
				status_code = _fork(token, args);
		}
		command_number++;
		command = NULL;
		token = NULL;
	}
	return (0);
}
