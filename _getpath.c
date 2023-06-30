#include "main.h"

/**
 * _getpath - function that builds full path to a command
 * @command: one argument it takes
 *
 * Return: full path to the command
 */

char *_getpath(char *command)
{
	struct stat sb;
	char *env = getenv("PATH"), *token = NULL, *s = NULL, *tmp = NULL;
	int i = 0, j = 0;

	if (env == NULL)
		return (NULL);
	s = strdup(env);
	token = strtok(s, ":\n");
	while (token != NULL)
	{
		i = 0, j = 0;
		tmp = malloc(strlen(token) + strlen(command) + 2);
		while (token[i] != '\0')
		{
			tmp[i] = token[i];
			i++;
		}
		tmp[i++] = '/';
		while (command[j] != '\0')
		{
			tmp[i] = command[j];
			i++;
			j++;
		}
		tmp[i] = '\0';
		if (stat(tmp, &sb) == 0)
		{
			free(s);
			return (tmp);
		}
		free(tmp);
		token = strtok(NULL, ":\n");
	}
	free(s);
	return (NULL);
}

