#include "main.h"

/**
 * main - function prototype
 * @argc: argument count of passed argument
 * @argv: argument vector
 * Return: 0
 */
int main(__attribute((unused))int argc, char **argv)
{
<<<<<<< HEAD
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
=======
	int status_code = 0, i = 0, command_number = 1;
	char *delimiter = " \t\n\r", *command = NULL;
	char **args = NULL;
>>>>>>> e172ee597ceb91d6b1f1eb36775c745e2bd25183
	size_t length = 0;
	ssize_t r = 0;
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
		_should_exit(command, status_code);
		if (args != NULL && args[0] != NULL)
		{
			if (stat(args[0], &sb) == -1)
				status_code = _perror(argv[0], command_number, args[0]);
			else
				status_code = _fork(args[0], args);
		}
		else if (args == NULL)
			status_code = _perror(argv[0], command_number, command);
		if (args != NULL)
		{
			for (i = 0; args[i] != NULL; i++)
				free(args[i]);
			free(args);
		}
		command_number++;
	}
	return (0);
}
