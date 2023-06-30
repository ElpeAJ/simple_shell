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
	char delimiter[] = {' ', '\n'};
	char **args = NULL;
	char *command = NULL;
	size_t length = 0;
	int i = 0;
	ssize_t r = 0;
	int command_number = 1;
	struct stat sb;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		r = getline(&command, &length, stdin);

		if (r == -1)
		{
			free(command);
			exit(status_code);
		}
		i = 0;
		args = _tokenizer(command, delimiter);
		if (args[i] != NULL)
		{
			if (stat(args[i], &sb) == -1)
				status_code = _perror(argv[i], command_number, args[i]);
			else
				status_code = _fork(args[i], args);
			command_number++;
			i++;
		}
		for (i = 0; args[i] != NULL; i++)
			free(args[i]);
		free(args);
	}
	command = NULL;
	return (0);
}
