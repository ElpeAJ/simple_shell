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
	char *token = NULL, *tmp = NULL, *save = NULL;

	token = strtok_r(command, delimiter, &save);
	while (token != NULL)
	{
		if (i == 0 && token[0] != '.')
		{
			if (token[0] != '/')
			{
				tmp = _getpath(token);
				if (tmp == NULL)
				{
					free(store_args);
					return (NULL);
				}
				store_args[0] = _getpath(token);
				strcpy(store_args[i], tmp);
				free(tmp);
			}
			else
			{
				store_args[i] = malloc(strlen(token) + 1);
				strcpy(store_args[i], token);
			}
		}
		else
		{
			store_args[i] = malloc(strlen(token) + 1);
			strcpy(store_args[i], token);
		}
		i++;
		token = strtok_r(NULL, delimiter, &save);
	}
	store_args[i] = NULL;

	return (store_args);
}

