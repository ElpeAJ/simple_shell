#include "main.h"

/**
 * main - function prototype
 * @argc: argument count of passed argument
 * @argv: argument vector
 * Return: 0
 */
int main(__attribute((unused))int argc, __attribute((unused))char **argv)
{
<<<<<<< HEAD
	int status_code;
	char delimiter[] = {' ', '\n'};
	char **args = malloc(sizeof(char *) * 2048);
=======
	int status_code = 0;
	char *delimiter = " \t\n\r";
	char **args = NULL;
>>>>>>> b29cdb699b669b2905ae25a2dbc97b0e1aa0be0c
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
		args = _tokenizer(command, delimiter);
		if (args[0] != NULL)
		{
			if (stat(args[0], &sb) == -1)
				status_code = _perror(argv[0], command_number, args[0]);
			else
				status_code = _fork(args[0], args);
			command_number++;
		}
		for (i = 0; args[i] != NULL; i++)
			free(args[i]);
		free(args);
	}
	command = NULL;
	return (0);
}
