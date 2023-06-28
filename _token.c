#include "main.h"

/**
 * _tokenizer - main function that...
 * @command: first parameter
 * @delimiter: second parameter
 *
 * Return: store_args
 */

char **_tokenizer(char *command, char *delimiter)
{
	char **store_args = malloc(sizeof(char *) * 2048);
	int i = 0;
	char *token;

	token = strtok(command, delimiter);
	while (token != NULL)
	{
		store_args[i] = malloc(strlen(token) + 1);
		strcpy(store_args[i], token);
		i++;
		token = strtok(NULL, delimiter);
	}
	store_args[i] = NULL;

	return (store_args);
}

